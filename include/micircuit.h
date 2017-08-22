#ifndef __H_MICIRCUIT_H__
#define __H_MICIRCUIT_H__

#include "board.h"
#include "boardIterator.h"
#include <functional>
#include <chrono>
#include <thread>
#include <queue>
#include <utility>
#include <thread>

namespace tmc { namespace mcc {
    
class MiCircuit {
protected:
    Board mboard;

    typedef std::chrono::steady_clock::time_point time_point;
    typedef std::chrono::duration<int, std::milli> duration;
    duration period;
    time_point start;
    time_point lastTick;
    std::thread timer;
    bool paused;

    // Construct a loop list representing object to update in this tick and next tick.
    struct _EventQueue{
        _EventQueue(_EventQueue *n):next(n) {}
        // an update event can be represented as a Position and an Origin Direction
        std::queue<Transform> pending;
        _EventQueue *next;
    } *update;

    void boardUpdate(Unit _old, Unit _new);

    void tick();
    /* trigger an event */
    void trigger(const char *);
public:
    MiCircuit();
    MiCircuit(const Size &s);
    ~Micircuit();
    Board &board();

    /* Start a `updating` thread updating status in `update` queue every `period` */
    void run(duration d);
    /* Pause the `updating` thread */
    void pause();
    /* Reset all the status of the units on the board*/
    void reset();
    /* Add an event callback */
    int addEventListener(const char *eventName, std::function<void(const char *)> c);
    /* Remove an event callback */
    void removeEventListener(int id);
    /* Put an unit onto the board at position p if that unit doesn't exist */
    const Unit &put(const Transform::Position &p, const Unit &u);
    /* Replace the unit at position p to u */
    const Unit &replace(const Transform::Position &p, const Unit &u);
    /* Remove the unit at position p */
    const Unit &remove(const Transform::Position &p);
    /* Get the unit at the position p */
    const Unit &get(const Transform::Position &p);
};

}}

#endif