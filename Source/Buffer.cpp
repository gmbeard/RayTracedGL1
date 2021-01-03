#include "Buffer.h"

Buffer::Buffer()
    :
    device(VK_NULL_HANDLE),
    buffer(VK_NULL_HANDLE),
    memory(VK_NULL_HANDLE),
    address(0),
    size(0),
    isMapped(false)
{}

Buffer::~Buffer()
{
    Destroy();
}

void Buffer::Init(
    VkDevice bdevice, const PhysicalDevice &physDevice, 
    VkDeviceSize bsize, VkBufferUsageFlags usage,
    VkMemoryPropertyFlags properties, const char *debugName)
{
    if (bsize == 0)
    {
        assert(0);
        return;
    }

    device = bdevice;

    VkResult r;

    VkBufferCreateInfo bufferInfo = {};
    bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferInfo.size = bsize;
    bufferInfo.usage = usage;
    bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    r = vkCreateBuffer(device, &bufferInfo, nullptr, &buffer);
    VK_CHECKERROR(r);

    VkMemoryRequirements memReq = {};
    vkGetBufferMemoryRequirements(device, buffer, &memReq);

    memory = physDevice.AllocDeviceMemory(memReq, properties, true);

    r = vkBindBufferMemory(device, buffer, memory, 0);
    VK_CHECKERROR(r);

    if (bufferInfo.usage & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)
    {
        VkBufferDeviceAddressInfoKHR addrInfo = {};
        addrInfo.sType = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
        addrInfo.buffer = buffer;
        address = vkGetBufferDeviceAddress(device, &addrInfo);
    }

    if (debugName != nullptr)
    {
        SET_DEBUG_NAME(device, buffer, VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT, debugName);
    }

    size = bsize;
}

void Buffer::Destroy()
{
    assert(!isMapped);

    if (device == VK_NULL_HANDLE)
    {
        return;
    }

    if (memory != VK_NULL_HANDLE)
    {
        vkFreeMemory(device, memory, nullptr);
        memory = VK_NULL_HANDLE;
    }

    if (buffer != VK_NULL_HANDLE)
    {
        vkDestroyBuffer(device, buffer, nullptr);
        buffer = VK_NULL_HANDLE;
    }

    address = 0;
    size = 0;
}

void *Buffer::Map()
{
    assert(device != VK_NULL_HANDLE);
    assert(!isMapped);
    assert(memory != VK_NULL_HANDLE && size > 0);

    isMapped = true;
    void *mapped;

    VkResult r = vkMapMemory(device, memory, 0, size, 0, &mapped);
    VK_CHECKERROR(r);

    return mapped;
}

void Buffer::Unmap()
{
    assert(device != VK_NULL_HANDLE);
    assert(isMapped);
    isMapped = false;
    vkUnmapMemory(device, memory);
}

bool Buffer::TryUnmap()
{
    assert(device != VK_NULL_HANDLE);

    if (isMapped)
    {
        Unmap();
        return true;
    }

    return false;
}

VkBuffer Buffer::GetBuffer() const
{
    assert(buffer != VK_NULL_HANDLE);
    return buffer;
}

VkDeviceMemory Buffer::GetMemory() const
{
    assert(memory != VK_NULL_HANDLE);
    return memory;
}

VkDeviceAddress Buffer::GetAddress() const
{
    assert(address != 0);
    return address;
}

VkDeviceSize Buffer::GetSize() const
{
    assert((buffer != VK_NULL_HANDLE && size != 0) || (buffer == VK_NULL_HANDLE && size == 0));
    return size;
}

bool Buffer::IsMapped() const
{
    return isMapped;
}

bool Buffer::IsInitted() const
{
    return buffer != VK_NULL_HANDLE && memory !=VK_NULL_HANDLE;
}