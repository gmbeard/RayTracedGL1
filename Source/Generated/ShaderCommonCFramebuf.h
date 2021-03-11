// This file was generated by GenerateShaderCommon.py

#pragma once

#include "../Common.h"

namespace RTGL1
{

#define FB_SAMPLER_INVALID_BINDING 0xFFFFFFFF

enum FramebufferImageIndex
{
    FB_IMAGE_INDEX_ALBEDO = 0,
    FB_IMAGE_INDEX_NORMAL = 1,
    FB_IMAGE_INDEX_NORMAL_PREV = 2,
    FB_IMAGE_INDEX_NORMAL_GEOMETRY = 3,
    FB_IMAGE_INDEX_NORMAL_GEOMETRY_PREV = 4,
    FB_IMAGE_INDEX_METALLIC_ROUGHNESS = 5,
    FB_IMAGE_INDEX_METALLIC_ROUGHNESS_PREV = 6,
    FB_IMAGE_INDEX_DEPTH = 7,
    FB_IMAGE_INDEX_DEPTH_PREV = 8,
    FB_IMAGE_INDEX_RANDOM_SEED = 9,
    FB_IMAGE_INDEX_RANDOM_SEED_PREV = 10,
    FB_IMAGE_INDEX_UNFILTERED_DIRECT = 11,
    FB_IMAGE_INDEX_UNFILTERED_SPECULAR = 12,
    FB_IMAGE_INDEX_UNFILTERED_INDIRECT = 13,
    FB_IMAGE_INDEX_SURFACE_POSITION = 14,
    FB_IMAGE_INDEX_VISIBILITY_BUFFER = 15,
    FB_IMAGE_INDEX_VISIBILITY_BUFFER_PREV = 16,
    FB_IMAGE_INDEX_VIEW_DIRECTION = 17,
    FB_IMAGE_INDEX_FINAL = 18,
    FB_IMAGE_INDEX_MOTION = 19,
    FB_IMAGE_INDEX_DIFF_ACCUM_COLOR = 20,
    FB_IMAGE_INDEX_DIFF_ACCUM_COLOR_PREV = 21,
    FB_IMAGE_INDEX_DIFF_ACCUM_MOMENTS = 22,
    FB_IMAGE_INDEX_DIFF_ACCUM_MOMENTS_PREV = 23,
    FB_IMAGE_INDEX_DIFF_ACCUM_HISTORY_LENGTH = 24,
    FB_IMAGE_INDEX_DIFF_ACCUM_HISTORY_LENGTH_PREV = 25,
    FB_IMAGE_INDEX_DIFF_COLOR_HISTORY = 26,
    FB_IMAGE_INDEX_SPEC_ACCUM_COLOR_AND_HISTORY_LENGTH = 27,
    FB_IMAGE_INDEX_SPEC_ACCUM_COLOR_AND_HISTORY_LENGTH_PREV = 28,
    FB_IMAGE_INDEX_DIFF_PING_COLOR_AND_VARIANCE = 29,
    FB_IMAGE_INDEX_DIFF_PONG_COLOR_AND_VARIANCE = 30,
    FB_IMAGE_INDEX_GRADIENT_SAMPLES = 31,
    FB_IMAGE_INDEX_GRADIENT_SAMPLES_PREV = 32,
    FB_IMAGE_INDEX_PING_GRADIENT = 33,
    FB_IMAGE_INDEX_PONG_GRADIENT = 34,
};

enum FramebufferImageFlagBits
{
    FB_IMAGE_FLAGS_FRAMEBUF_FLAGS_FORCE_1X1_SIZE = 4,
    FB_IMAGE_FLAGS_FRAMEBUF_FLAGS_FORCE_HALF_X_SIZE = 8,
    FB_IMAGE_FLAGS_FRAMEBUF_FLAGS_FORCE_HALF_Y_SIZE = 16,
};
typedef uint32_t FramebufferImageFlags;

extern const uint32_t ShFramebuffers_Count;
extern const VkFormat ShFramebuffers_Formats[];
extern const FramebufferImageFlags ShFramebuffers_Flags[];
extern const uint32_t ShFramebuffers_Bindings[];
extern const uint32_t ShFramebuffers_BindingsSwapped[];
extern const uint32_t ShFramebuffers_Sampler_Bindings[];
extern const uint32_t ShFramebuffers_Sampler_BindingsSwapped[];
extern const char *const ShFramebuffers_DebugNames[];

}