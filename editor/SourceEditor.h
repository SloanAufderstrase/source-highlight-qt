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

    void setColorLineNumberArea(const QString &, const QString &);
    void setColorCurrentLineBackground(const QString &);
    void setTabWidth(int);
    bool tabWidth();
    void setSpaceAsTab(bool);
    bool spaceAsTab();

protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

private:
    QWidget *m_lineNumberArea;
    QColor   m_colorCurrentLine;
    QColor   m_colorLineNumberAreaBackground;
    QColor   m_colorLineNumberAreaForeground;
    bool     m_spaceAsTab = false;
    int      m_tabWidth = 4;

    void setColor(const QString &color, QColor &colorObject);
    void indentSelected(QKeyEvent *event);
};

#endif//__SOURCEEDITOR_H__
