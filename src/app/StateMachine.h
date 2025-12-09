/*
 * StateMachine.h
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#ifndef SRC_APP_STATEMACHINE_H_
#define SRC_APP_STATEMACHINE_H_

#pragma once

#include <string>
#include <functional>
#include "AppModel.h"

enum class AppState
{
    BOOT = 0,
    RUNNING,
    WARNING,
    ERROR,
    SHUTDOWN
};

class StateMachine
{
public:
    StateMachine();

    // Yeni J1939 verisi geldiğinde state makineyi değerlendir
    void evaluate(const VehicleStatus& status);

    // Geçerli state’i al
    AppState getState() const;

    // State değiştiğinde callback (GUI veya log’a)
    void setStateChangedCallback(std::function<void(AppState)> cb);

private:
    AppState state;
    std::function<void(AppState)> onStateChanged;

    void changeState(AppState newState);

    // State decision logic
    AppState evaluateState(const VehicleStatus& status);
};

#endif /* SRC_APP_STATEMACHINE_H_ */
