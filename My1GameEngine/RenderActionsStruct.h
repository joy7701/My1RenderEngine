#pragma once
// RenderCommand enum int type of RenderSystem processed commands
enum class RenderCommand : int { AddMesh, AddShader, DrawMesh };

// exchange sturctures with RenderSystem
// STRUCT FOR: 3d mesh STRUCT FORMAT: 3 floats xyz normalized storing in single VBO in a single VAO
struct Data3DMesh
{
    unsigned int* Graphics3DMeshVAOId; // VAO of future Mesh
    unsigned int* Graphics3DMeshEBOId; // id of EBO mesh
    unsigned int* Graphics3DMeshVBOId; // unique ID attached to buffer on GPU
    float* Graphics3DMeshPointer; // pointer at begin array of floats
    unsigned long long Graphics3DMeshSizeOfArray; // size of 3d mesh in bytes
    unsigned int* Graphics3DMeshIndicesPointer; // pointer at begin of mesh indices
    unsigned long long Graphics3DMeshIndicesSizeOfArray; // size of 3d mesh indices array in bytes
    bool GraphicsGenerateNewVAO; // flag to generate new VAO

    Data3DMesh(unsigned int* _Graphics3DMeshVAOId, unsigned int* _Graphics3DMeshEBOId, unsigned int* _Graphics3DMeshVBOId,
        float* _Graphics3DMeshPointer, unsigned long long _Graphics3DMeshSizeOfArray,
        unsigned int* _Graphics3DMeshIndicesPointer, unsigned long long _Graphics3DMeshIndicesSizeOfArray,
        bool _GraphicsGenerateNewVAO)
    {
        // ID assignments
        Graphics3DMeshVAOId = _Graphics3DMeshVAOId;
        Graphics3DMeshEBOId = _Graphics3DMeshEBOId;
        Graphics3DMeshVBOId = _Graphics3DMeshVBOId;
        // Mesh data assignments
        Graphics3DMeshPointer = _Graphics3DMeshPointer;
        Graphics3DMeshSizeOfArray = _Graphics3DMeshSizeOfArray;
        // Mesh indices assignments
        Graphics3DMeshIndicesPointer = _Graphics3DMeshIndicesPointer;
        Graphics3DMeshIndicesSizeOfArray = _Graphics3DMeshIndicesSizeOfArray;
        // Flag to generate new VAO assignment
        GraphicsGenerateNewVAO = _GraphicsGenerateNewVAO;
    }
};

// STRUCT FOR: shader data STRUCT FORMAT: info includes vertex+fragment shader
struct DataShader
{
    const char** GraphicsVertexShaderTextPointer; // pointer to pointer of text begin vertex shader
    const char** GraphicsFragmentShaderTextPointer; // pointer to pointer of text begin fragment shader
    unsigned int* GraphicsShaderProgramId;// id pointer to use shader

    DataShader(const char** _GraphicsVertexShaderTextPointer, const char** _GraphicsFragmentShaderTextPointer, unsigned int* _GraphicsShaderProgramId)
    {
        GraphicsVertexShaderTextPointer = _GraphicsVertexShaderTextPointer;
        GraphicsFragmentShaderTextPointer = _GraphicsFragmentShaderTextPointer;
        GraphicsShaderProgramId = _GraphicsShaderProgramId;
    }
};

//STURCT FOR: drawing 3d mesh STRUCT FORMAT: 3d model(VAO) + compiled shader program
struct DataDraw
{
    unsigned int* Graphics3DMeshVAOId; // VAO of mesh
    unsigned int* GraphicsShaderProgramId; // shader program for drawing
    int Graphics3DMeshIndicesLength; // length of index array; count of elements

    DataDraw(unsigned int* _Graphics3DMeshVAOId, unsigned int* _GraphicsShaderProgramId, int _Graphics3DMeshIndicesLength)
    {
        Graphics3DMeshVAOId = _Graphics3DMeshVAOId;
        GraphicsShaderProgramId = _GraphicsShaderProgramId;
        Graphics3DMeshIndicesLength = _Graphics3DMeshIndicesLength;
    }
};