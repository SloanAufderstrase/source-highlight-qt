#ifndef __LINENUMBERAREA_H__
#define __LINENUMBERAREA_H__

#include "SourceEditor.h"
#include <QWidget>

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(SourceEditor *editor);
    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    SourceEditor *m_sourceEditor;
};

#endif//__LINENUMBERAREA_H__
