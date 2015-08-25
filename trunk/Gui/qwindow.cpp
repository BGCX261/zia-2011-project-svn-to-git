#include "qwindowapi.h"

QWindowAPI::QWindowAPI(const char *name, int width, int height, bool frame, QString logo, QString filename)
{

}

QWindowAPI::~QWindowAPI()
{

}

void         QWindowAPI::mousePressEvent(QMouseEvent *event)
{
  m_Diff = event->pos();
  setCursor(QCursor(Qt::SizeAllCursor));
}

void          QWindowAPI::mouseReleaseEvent(QMouseEvent *event)
{
  Q_UNUSED(event);
  setCursor(QCursor(Qt::ArrowCursor));
}

void          QWindowAPI::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->globalPos();
    window()->move(p - m_Diff);
}

QLabel        *QWindowAPI::CreateLink(QWidget *widget, QString text, int pos_x, int pos_y, const QString type)
{
    QLabel *label = new QLabel(widget);

    label->setText(text);
    label->move(pos_x, pos_y);
    label->setObjectName("label");
    label->setStyleSheet("QLabel {color:white;text-decoration:underline;} QLabel:hover {color:red;}");
    label->show();
    return (label);
}

QLabel        *QWindowAPI::CreateText(QWidget *widget, QString text, int width, int height, int pos_x, int pos_y)
{
    QLabel *label = new QLabel(widget);

    label->setText(text);
    label->move(pos_x, pos_y);
    label->setWordWrap(true);
    label->setFixedSize(width, height);
    label->show();
    return (label);
}

QPushButton *QWindowAPI::CreateButton(QWidget *widget, const char *name, int height, int width, int pos_x, int pos_y, const QString stylesheet)
{
    QPushButton *_button;
    _button = new QPushButton(name, widget);
    _button->move(pos_x, pos_y);
    _button->setFixedSize(width, height);
    _button->setStyleSheet(stylesheet);
    _button->setObjectName("link1");
    _button->show();
return (_button);
}

QLabel    *QWindowAPI::CreateImage(QWidget *widget, const QString filename, int height, int width, int pos_x, int pos_y)
{
    QLabel *label = new QLabel(widget);
    QImage image = QImage();

    bool tmp = image.load(filename);
    if (!tmp)
        QMessageBox::warning(this, "Error", "Failed to load image", 0, 0);
    label->setFixedSize(width, height);
    label->move(pos_x, pos_y);
    label->setPixmap(QPixmap::fromImage(image));
    label->setScaledContents(true);
    label->show();
    return (label);
}

QPushButton    *QWindowAPI::CreateClickableImage(QWidget *widget, const QString filename, int height, int width, int pos_x, int pos_y)
{
    QPushButton *_button;
    QIcon icon;
    QSize size;

    size.setHeight(height);
    size.setWidth(width);
    icon.addFile(filename);
    _button = new QPushButton(widget);
    _button->move(pos_x, pos_y);
    _button->setFixedSize(width, height);
    _button->setFlat(true);
    _button->setFocusPolicy(Qt::NoFocus);
    _button->setIcon(icon);
    _button->setIconSize(size);
    _button->setStyleSheet("QPushButton{ border: none; };");
    _button->show();
    return (_button);
}

QLineEdit    *QWindowAPI::CreateInputBox(QWidget *widget, int height, int width, int pos_x, int pos_y, int mode)
{
    QLineEdit *line;

    line = new QLineEdit(widget);
    line->move(pos_x, pos_y);
    line->show();
    if (mode == QLineEdit::Password)
      line->setEchoMode(QLineEdit::Password);
    line->setFixedSize(width, height);
    return (line);
}
