#ifdef DEBUG
#include <iostream>
#endif
#include "../include/micircuit.h"
namespace tmc { namespace mcc {
    MiCircuit::MiCircuit():paused(false)
    {
        // Construct a loop list  (1 -> 2 -> 1)
        update = new _EventQueue(nullptr);
        update->next = new _EventQueue(update);
        mboard.updateCallback = std::bind(&MiCircuit::boardUpdate, *this);
    }
    MiCircuit::MiCircuit(const Size &s):MiCircuit(),mboard(s) {}

    ~MiCircuit::MiCircuit()
    {
        delete update->next;
        delete update;
    }

    void MiCircuit::boardUpdate(Unit o, Unit n)
    {
        // todo: trigger update event and add object to update queue
    }

    Board &MiCircuit::board()
    {
        return mboard;
    }

    void MiCircuit::tick()
    {
        #ifdef DEBUG
        cout << "<tick>";
        #endif
    }

    void MiCircuit::run()
    {
        if (timer.joinable())
        {
            paused = false;
            return;
        }

        timer = thread([&](){
            while (true)
            {
                if (paused)
                    continue;
                std::this_thread::sleep_until(lastTick + period);
                tick();
            }
        });
    }

    void MiCircuit::pause()
    {
        paused = true;
    }

    void MiCircuit::reset()
    {
        // todo: clear all the status
    }

    int MiCircuit::addEventListener(const char *e, std::function<void(const char *)> callback)
    {
        // todo: event system
    }

    void MiCircuit::removeEventListener(int id)
    {
        // todo: event system
    }

    void MiCircuit::trigger(const char *e)
    {
        // todo: event system
    }

    const Unit &MiCircuit::put(const Transform::Position &p, const Unit &u)
    {
        return mboard.put(p, u).get(p);
    }

    const Unit &MiCircuit::replace(const Transform::Position &p, const Unit &u)
    {
        return mboard.replace(p, u).get(p);
    }

    const Unit &MiCircuit::remove(const Transform::Position &p);
    {
        return mboard.remove(p).get(p);
    }

    const Unit &MiCircuit::get(const Transform::Position &p)
    {
        return mboard.get(p);
    }
}}