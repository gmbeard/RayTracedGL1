// Copyright (c) 2020-2021 Sultim Tsyrendashiev
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "Common.h"
#include "RTGL1/RTGL1.h"

#include <cstddef>

namespace RTGL1
{

namespace Utils
{
    void BarrierImage(
        VkCommandBuffer cmd, VkImage image,
        VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask,
        VkImageLayout oldLayout, VkImageLayout newLayout,
        VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
        const VkImageSubresourceRange &subresourceRange);

    void BarrierImage(
        VkCommandBuffer cmd, VkImage image,
        VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask,
        VkImageLayout oldLayout, VkImageLayout newLayout,
        const VkImageSubresourceRange &subresourceRange);

    void BarrierImage(
        VkCommandBuffer cmd, VkImage image,
        VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask,
        VkImageLayout oldLayout, VkImageLayout newLayout,
        VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask);

    void BarrierImage(
        VkCommandBuffer cmd, VkImage image,
        VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask,
        VkImageLayout oldLayout, VkImageLayout newLayout);

    void ASBuildMemoryBarrier(
        VkCommandBuffer cmd
    );

    void WaitForFence(VkDevice device, VkFence fence);
    void ResetFence(VkDevice device, VkFence fence);
    void WaitAndResetFence(VkDevice device, VkFence fence);
    void WaitAndResetFences(VkDevice device, VkFence fence_A, VkFence fence_B);

    uint32_t Align(uint32_t value, uint32_t alignment);

    bool AreViewportsSame(const VkViewport &a, const VkViewport &b);

    bool IsAlmostZero(const RgFloat3D &v);
    bool IsAlmostZero(const RgMatrix3D &m);
    // In terms of GLSL: mat3(a), where a is mat4.
    // The remaining values are initialized with identity matrix.
    void SetMatrix3ToGLSLMat4(float dst[16], const RgMatrix3D &src);

    uint32_t GetPreviousByModulo(uint32_t value, uint32_t count);
    
    uint32_t GetWorkGroupCount(float size, uint32_t groupSize);
    uint32_t GetWorkGroupCount(uint32_t size, uint32_t groupSize);
};

template<typename T>
T clamp(const T &v, const T &v_min, const T &v_max)
{
    assert(v_min <= v_max);
    return std::min(v_max, std::max(v_min, v));
}

template<typename T, std::size_t N>
constexpr auto size(T const(&)[N]) noexcept -> std::size_t
{
    return N;
}

}
