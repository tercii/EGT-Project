#include <egt/ui>
#include <iostream>                 // ← EKLENDİ

#include "can/SocketCanDriver.h"
#include "j1939/J1939Stack.h"
#include "app/AppModel.h"
#include "app/EventBus.h"
#include "gui/DashboardView.h"

int main(int argc, char** argv)
{
    egt::Application app(argc, argv);

    EventBus bus;
    AppModel model;

    SocketCanDriver can;
    J1939Stack j1939(bus);

    can.setReceiveCallback([&](const can_frame& f){
        j1939.onCanFrame(f);
    });

    if (!can.open("can0"))
    {
        std::cerr << "CAN0 açılamadı!" << std::endl;
    }

    DashboardView gui(bus, model);
    gui.show();

    return app.run();
}
