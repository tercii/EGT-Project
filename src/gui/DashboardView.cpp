#include "DashboardView.h"

DashboardView::DashboardView(EventBus& bus, AppModel& m)
    : model(m)
{
    // --- Title ---
    title = std::make_shared<egt::Label>("VEHICLE DASHBOARD");
    title->font(egt::Font(28, egt::Font::Weight::bold));
    title->align(egt::AlignFlag::center_horizontal);
    title->resize(egt::Size(size().width(), 50));
    title->move(egt::Point(0, 10));
    add(*title);

    // --- RPM ---
    rpm_label = std::make_shared<egt::Label>("RPM: 0");
    rpm_label->font(egt::Font(26));
    rpm_label->resize(egt::Size(size().width(), 40));
    rpm_label->move(egt::Point(0, 80));
    rpm_label->align(egt::AlignFlag::center_horizontal);
    add(*rpm_label);

    // --- Lamp Status ---
    lamp_label = std::make_shared<egt::Label>("LAMPS: -");
    lamp_label->font(egt::Font(22));
    lamp_label->resize(egt::Size(size().width(), 40));
    lamp_label->move(egt::Point(0, 140));

    lamp_label->align(egt::AlignFlag::center_horizontal);
    add(*lamp_label);

    // --- DTC ---
    dtc_label = std::make_shared<egt::Label>("No Active DTC");
    dtc_label->font(egt::Font(22));
    dtc_label->resize(egt::Size(size().width(), 40));
    dtc_label->move(egt::Point(0, 200));
    dtc_label->align(egt::AlignFlag::center_horizontal);
    add(*dtc_label);

    // Subscribe J1939
    bus.subscribe("VehicleStatusUpdated", [&](const VehicleStatus& s){
        model.updateFromJ1939(s);
        dirty = true;
    });

    // Screen update timer
    gui_timer.on_timeout([this]() {
        if(dirty)
        {
            dirty = false;
            updateUI();
        }
    });

    gui_timer.start(std::chrono::milliseconds(100));
}

void DashboardView::updateUI()
{
    auto s = model.getStatus();

    rpm_label->text("RPM: " + std::to_string((int)s.engineSpeed));

    lamp_label->text(
        "MIL:" + std::to_string((int)s.mil) +
        " RSL:" + std::to_string((int)s.rsl) +
        " AWL:" + std::to_string((int)s.awl) +
        " PL:"  + std::to_string((int)s.pl)
    );

    if (s.activeDTC.spn != 0)
    {
        dtc_label->text(
            "DTC  SPN:" + std::to_string(s.activeDTC.spn) +
            " FMI:" + std::to_string(s.activeDTC.fmi)
        );
    }
    else
    {
        dtc_label->text("No Active DTC");
    }
}
