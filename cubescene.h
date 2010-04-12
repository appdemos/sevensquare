#ifndef CUBESCENE_H
#define CUBESCENE_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "cubecellitem.h"

#define CUBE_WIDTH 320
#define CUBE_HEIGHT 240

#define CELL_WIDTH 60

#define MIN_PAD 15

#define ROW_SIZE ((CUBE_HEIGHT - MIN_PAD) / CELL_WIDTH)
#define COL_SIZE ((CUBE_WIDTH - MIN_PAD) / CELL_WIDTH)

#define X_PAD ((CUBE_WIDTH - CELL_WIDTH * COL_SIZE)/2)
#define Y_PAD ((CUBE_HEIGHT - CELL_WIDTH * ROW_SIZE)/2)

#define GRID_COLOR 120, 120, 120
#define GRID_WIDTH 1

#define WHITE_CELL_COLOR "White"
#define WHITE_CELL_POS -1
#define WHITE_CELL_IDX (WHITE_CELL_POS * 2)

#define THUMNAIL_X_PAD 6
#define THUMNAIL_CELL_POS -2
#define THUMNAIL_CELL_IDX (THUMNAIL_CELL_POS * 2)

#define STARTBUTTON_X_PAD 6
#define STARTBUTTON_CELL_POS -3
#define STARTBUTTON_CELL_IDX (STARTBUTTON_CELL_POS * 2)

#define BACKGROUND_FILE "gnu_tux-320x240.png"

class CubeScene : public QGraphicsScene
{
public:
    CubeScene(QObject * parent = 0);

    void initialize (const QString &image_file = "");

    void startPlay(void);

    void moveAllCell(const QPoint &pos, int off_row, int off_col);

    void moveCell(const QPoint &pos, int row, int col);

    void checkAllCell(void);

    void setBgVisible(bool visible) { bg_mask->setVisible(visible); };
    bool getBgVisible(void)         { return bg_mask->isVisible(); };

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsRectItem *bg_mask;
    CubeCellItem    *b_items[ROW_SIZE][COL_SIZE];
    CubeCellItem    *b_curr_items[ROW_SIZE][COL_SIZE];
    int m_white_row;
    int m_white_col;
};

#endif // CUBESCENE_H
