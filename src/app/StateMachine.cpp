/*
 * StateMachine.cpp
 *
 *  Created on: Dec 3, 2025
 *      Author: nimbus
 */

#include "StateMachine.h"
#include <iostream>
#include <mutex>

static std::mutex sm_mutex;

StateMachine::StateMachine()
    : state(AppState::BOOT)
{
}

void StateMachine::setStateChangedCallback(std::function<void(AppState)> cb)
{
    onStateChanged = cb;
}

AppState StateMachine::getState() const
{
    std::lock_guard<std::mutex> lock(sm_mutex);
    return state;
}

void StateMachine::changeState(AppState newState)
{
    std::lock_guard<std::mutex> lock(sm_mutex);

    if (state == newState)
        return;

    state = newState;

    if (onStateChanged)
        onStateChanged(state);

    // Debug (istersen log atma)
    std::cout << "[FSM] New State: " << (int)state << std::endl;
}

AppState StateMachine::evaluateState(const VehicleStatus& status)
{
    // Error state → severe diagnostic or SPN=0xFFFF
    if (status.activeDTC.spn == 0xFFFF)
        return AppState::ERROR;

    // Warning state → MIL / RSL / AWL / PL ON or FLASH
    if (status.mil != LampStatus::OFF ||
        status.rsl != LampStatus::OFF ||
        status.awl != LampStatus::OFF ||
        status.pl  != LampStatus::OFF)
        return AppState::WARNING;

    // Running (Engine speed above threshold)
    if (status.engineSpeed > 200)
        return AppState::RUNNING;

    return AppState::BOOT;
}

void StateMachine::evaluate(const VehicleStatus& status)
{
    AppState next = evaluateState(status);
    changeState(next);
}

