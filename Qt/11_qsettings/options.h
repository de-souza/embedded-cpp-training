#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QSettings>
#include <QAbstractButton>

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();
    static int StyleToIndex(const QFont::Style style);
    static QFont::Style IndexToStyle(const int index);
    static int WeightToIndex(const QFont::Weight weight);
    static QFont::Weight IndexToWeight(const int index);

private slots:
    void mOnClick(QAbstractButton *button);
    void mSetFontFamily(const QFont& font);
    void mSetFontStyle(const int& index);
    void mSetFontSize(const int& size);
    void mSetFontWeight(const int& index);

private:
    Ui::Options *ui;
    QFont mCurrentFont;
    void mSaveFont(QFont font);
    void mLoadFont();
    void mUpdateExample();
};

#endif // OPTIONS_H
