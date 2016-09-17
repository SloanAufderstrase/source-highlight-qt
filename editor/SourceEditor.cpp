#include <QPainter>
#include <QTextBlock>
#include <QTextEdit>
#include "SourceEditor.h"
#include "LineNumberArea.h"

#define DEBUG
#ifdef DEBUG
#include <QDebug>
#define WARN(x) qDebug()<<x;
#else
#define WARN(x)
#endif

SourceEditor::SourceEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    m_lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect, int)), this, SLOT(updateLineNumberArea(QRect, int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

    m_colorCurrentLine = QColor(Qt::yellow).lighter(160);
    m_colorLineNumberAreaForeground = QColor(Qt::black);
    m_colorLineNumberAreaBackground = QColor(Qt::lightGray);

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}

SourceEditor::~SourceEditor()
{

}

int SourceEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());

    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

void SourceEditor::updateLineNumberAreaWidth(int newWidth)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void SourceEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy) {
        m_lineNumberArea->scroll(0, dy);
    } else {
        m_lineNumberArea->update(0, rect.y(), m_lineNumberArea->width(), rect.height());
    }
    if (rect.contains(viewport()->rect())) {
        updateLineNumberAreaWidth(0);
    }
}

void SourceEditor::resizeEvent(QResizeEvent *event)
{
    QPlainTextEdit::resizeEvent(event);

    QRect cr = contentsRect();
    m_lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void SourceEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if(!isReadOnly()) {
        QTextEdit::ExtraSelection selection;
        selection.format.setBackground(m_colorCurrentLine);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.movePosition(QTextCursor::StartOfBlock);
        selection.cursor.movePosition(QTextCursor::NextBlock, QTextCursor::KeepAnchor);
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void SourceEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(m_lineNumberArea);
    painter.fillRect(event->rect(), m_colorLineNumberAreaBackground);
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
    while (block.isValid()  && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(m_colorLineNumberAreaForeground);
            painter.drawText(0, top, m_lineNumberArea->width(), fontMetrics().height() * block.lineCount(), Qt::AlignRight, number);
        }
        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

void SourceEditor::setColor(const QString &color, QColor &colorObject)
{
    if (color.isEmpty()) {
        return;
    }

    QColor newColor;
    if (color[0] == '#') {
        newColor.setNamedColor(color);
    } else {
        newColor.setNamedColor("#" + color);
    }

    if (newColor.isValid()) {
        colorObject = newColor;
    } else {
        WARN("Invalid color detected");
    }
}

void SourceEditor::setColorLineNumberArea(const QString &fg, const QString &bg)
{
    setColor(fg, m_colorLineNumberAreaForeground);
    setColor(bg, m_colorLineNumberAreaBackground);
}

//void SourceEditor::setLineNumberAreaPadding(int left, int right)
//{
    
//}
