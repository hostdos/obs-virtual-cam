#ifndef VIRTUAL_PROPERTIES_H
#define VIRTUAL_PROPERTIES_H

#include <QDialog>
#include "obs.h"

struct vcam_update_data{
	bool horizontal_flip = false;
	bool keep_ratio = false;
};

namespace Ui {
class VirtualProperties;
}

class VirtualProperties : public QDialog
{
    Q_OBJECT

public:
    explicit VirtualProperties(QWidget *parent = 0);
    ~VirtualProperties();
	void SetVisable();
	void showEvent(QShowEvent *event);
	void closeEvent(QCloseEvent *event);

private Q_SLOTS:
	void onStart();
	void onStop();
	void onClickHorizontalFlip();
	void onClickKeepAspectRatio();

private:
    Ui::VirtualProperties *ui;
	struct obs_video_info video_info;
	struct vcam_update_data update_data;
	QString scene_name;
	void UpdateParameter();
	void SaveSetting();
};

#endif // VIRTUAL_PROPERTIES_H
