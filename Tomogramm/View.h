#pragma once

#pragma comment (lib, "opengl32.lib")

#include <qdebug.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>

#include <string>

#include "Data.h"

class View : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    Data data;
    int layer;

    short max;
    short min;

    float vertical_scale;
    float horizontal_scale;

    enum State
    {
        quads,
        quadstrip,
        texture,
        blank
    };
    State state;

    GLuint VBOtexture;
    QImage textureImage;

    View(QWidget* parent = nullptr);

    

protected:
    void initializeGL();
    void resizeGL(int width_, int height_);
    void paintGL();

    float TransferFunction(short value);
    short Clamp(short value, short min, short max);

    void genTextureImage();
    void Load2dTexture();
    
    void VisualizationQuads();
    void VisualizationQuadstrip();
    void VisualizationTexture();
    void VisualizationBlank();

public:
    void setLayer(int layer_);
    std::string nextMode();
    int setMin(int min_);
    int setMax(int max_);

    int getMin();
    int getMax();
    int getDepth();

    void load(QString path_, char direction_);
};

