#ifndef __SOURCEEDITOR_H__
#define __SOURCEEDITOR_H__

#include <QPlainTextEdit>

class SourceEditor : public QPlainTextEdit {
    Q_OBJECT
public:
    SourceEditor(QWidget *parent = 0);
    ~SourceEditor();

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

    void setColorLineNumberArea(const QString &fg, const QString &bg);

protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

private:
    QWidget *m_lineNumberArea;
    QColor m_colorCurrentLine;
    QColor m_colorLineNumberAreaBackground;
    QColor m_colorLineNumberAreaForeground;

    void setColor(const QString &color, QColor &colorObject);
};

#endif//__SOURCEEDITOR_H__
