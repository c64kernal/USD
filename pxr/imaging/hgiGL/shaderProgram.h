//
// Copyright 2020 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef PXR_IMAGING_HGIGL_SHADERPROGRAM_H
#define PXR_IMAGING_HGIGL_SHADERPROGRAM_H

#include "pxr/imaging/hgi/shaderProgram.h"

#include "pxr/imaging/hgiGL/api.h"
#include "pxr/imaging/hgiGL/shaderFunction.h"

#include <vector>

PXR_NAMESPACE_OPEN_SCOPE


///
/// \class HgiGLShaderProgram
///
/// OpenGL implementation of HgiShaderProgram
///
class HgiGLShaderProgram final : public HgiShaderProgram
{
public:
    HGIGL_API
    virtual ~HgiGLShaderProgram();

    HGIGL_API
    bool IsValid() const override;

    HGIGL_API
    std::string const& GetCompileErrors() override;

    HGIGL_API
    HgiShaderFunctionHandleVector const& GetShaderFunctions() const override;

    /// Returns the gl resource id of the program.
    HGIGL_API
    uint32_t GetProgramId() const;

protected:
    friend class HgiGL;

    HGIGL_API
    HgiGLShaderProgram(HgiShaderProgramDesc const& desc);

private:
    HgiGLShaderProgram() = delete;
    HgiGLShaderProgram & operator=(const HgiGLShaderProgram&) = delete;
    HgiGLShaderProgram(const HgiGLShaderProgram&) = delete;

private:
    std::string _errors;
    uint32_t _programId;
};


PXR_NAMESPACE_CLOSE_SCOPE

#endif