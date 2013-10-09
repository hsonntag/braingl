/*
 * fiberrenderer.h
 *
 * Created on: 28.12.2012
 * @author Ralph Schurade
 */

#ifndef FIBERRENDERER_H_
#define FIBERRENDERER_H_

#include "objectrenderer.h"

#include "../../thirdparty/newmat10/newmat.h"

#include <QColor>

class FiberSelector;
class PropertyGroup;

class FiberRenderer : public ObjectRenderer
{
    Q_OBJECT

public:
    FiberRenderer( FiberSelector* selector, QVector< QVector< float > >* data, QVector< QVector< float > >* extraData );
    virtual ~FiberRenderer();

    void init();

    void draw( QMatrix4x4 p_matrix, QMatrix4x4 mv_matrix, int width, int height, int renderMode, PropertyGroup* props );
    void updateExtraData( QVector< QVector< float > >* extraData );
protected:
    void setupTextures();
    void setShaderVars( PropertyGroup* props );

    void initGeometry();

    void initIndexBuffer( int lod );

private:
    QModelIndex createIndex( int branch, int pos, int column );


    FiberSelector* m_selector;
    GLuint vbo;
    GLuint dataVbo;
    GLuint indexVbo;

    QVector< QVector< float > >* m_data;
    QVector< QVector< float > >* m_extraData;
    QVector< QVector< float > >* m_indexData;

    int m_numLines;
    int m_numPoints;


    QVector<int>m_pointsPerLine;
    QVector<int>m_startIndexes;

    bool m_isInitialized;

    QVector<QColor>m_colorField;
    QVector<QVector3D>m_globalColorField;

public slots:
    void colorChanged( QVariant color );

private slots:
};

#endif /* FIBERRENDERER_H_ */
