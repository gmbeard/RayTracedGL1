// Copyright (c) 2021 Sultim Tsyrendashiev
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

#version 460

layout(push_constant) uniform DepthCopyingFrag_BT 
{
    uint renderWidth;
    uint renderHeight;
} depthCopyingPush;

#define CHECKERBOARD_FULL_WIDTH depthCopyingPush.renderWidth
#define CHECKERBOARD_FULL_HEIGHT depthCopyingPush.renderHeight

#define DESC_SET_FRAMEBUFFERS 0
#include "ShaderCommonGLSLFunc.h"

void main()
{
    const ivec2 pix = ivec2(gl_FragCoord.xy);
    gl_FragDepth = texelFetch(framebufDepth_Sampler, getCheckerboardPix(pix), 0).w;
}