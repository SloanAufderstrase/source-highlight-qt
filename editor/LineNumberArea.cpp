#include "LineNumberArea.h"

LineNumberArea::LineNumberArea(SourceEditor *editor) : QWidget(editor)
{
    m_sourceEditor = editor;
}

QSize LineNumberArea::sizeHint() const 
{
    return QSize(m_sourceEditor->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event)
{
    m_sourceEditor->lineNumberAreaPaintEvent(event);
}
