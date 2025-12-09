#pragma once
#include <egt/ui>
#include "../app/AppModel.h"
#include "../app/EventBus.h"

class DashboardView : public egt::TopWindow
{
public:
    DashboardView(EventBus& bus, AppModel& model);
    void updateUI();

private:
    AppModel& model;
    bool dirty = false;

    egt::PeriodicTimer gui_timer;

    std::shared_ptr<egt::Label> title;
    std::shared_ptr<egt::Label> rpm_label;
    std::shared_ptr<egt::Label> lamp_label;
    std::shared_ptr<egt::Label> dtc_label;
};
