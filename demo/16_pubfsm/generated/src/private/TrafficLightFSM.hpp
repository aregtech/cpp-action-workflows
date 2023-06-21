
//////////////////////////////////////////////////////////////////////////
// Begin generate TrafficLightFSM.hpp file
//////////////////////////////////////////////////////////////////////////

#pragma once

/************************************************************************
 * (c) copyright    2022
 *                  Generated by Aregtech code generator tool.
 * Generated at     03.01.2022  12:23:44 GMT+02:00 
 ************************************************************************/

/**
 * \file       	    generated/src/private/TrafficLightFSM.hpp
 * \ingroup         TrafficLight State Machine
 * \brief      	    This is an automatic generated code of TrafficLight 
 *                  State Machine class declaration.
 *                  Do not make changes in the file.
 *
 *                  NOTE:   This class is generated as thread unsafe. 
 *                          No locking mechanism accessing methods or variables is provided.
 *
 **/

/************************************************************************
 * Include files
 ************************************************************************/
#include "generated/src/private/NETrafficLightFSM.hpp"

#include "areg/base/String.hpp"
#include "areg/component/Timer.hpp"
#include "areg/component/IETimerConsumer.hpp"

/************************************************************************
 * Dependencies
 ************************************************************************/
class IETrafficLightActionHandler;
class DispatcherThread;

//////////////////////////////////////////////////////////////////////////
// TrafficLightFSM class declaration 
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   TrafficLightFSM is a generated State Machine class.
 *          Instantiate by passing reference of action handler.
 *          The actions will be triggered depending on states.
 **/
class TrafficLightFSM
{
//////////////////////////////////////////////////////////////////////////
// Internal classes
//////////////////////////////////////////////////////////////////////////
private:
//////////////////////////////////////////////////////////////////////////
// TrafficLightFSM::TrafficLightEventConsumer class declaration
//////////////////////////////////////////////////////////////////////////
    friend class TrafficLightEventConsumer;

    /**
     * \brief   TrafficLight state-machine event consumer to dispatch the events. 
     **/
    class TrafficLightEventConsumer : public NETrafficLightFSM::IEFsmEventConsumer
    {
    public:
        /**
         * \brief   Constructs and initializes TrafficLight Event Consumer object.
         * \param   fsm     The instance of state-machine.
         **/
        TrafficLightEventConsumer( TrafficLightFSM & fsm );

        virtual ~TrafficLightEventConsumer( void ) = default;

    private:
    /************************************************************************/
    // Event Consumer override
    /************************************************************************/
        /**
         * \brief   Process State Machine events.
         * \param   data    The Event Data object passed to event when fired.
         * \remark  The method is not thread safe.
         **/
        virtual void processEvent( const NETrafficLightFSM::FsmEventData & data ) override;

    private:
    /************************************************************************/
    // Hidden member variables
    /************************************************************************/
        /**
         * \brief   The instance of TrafficLight state-mashine. 
         **/
        TrafficLightFSM &   mFsm;

    private:
    /************************************************************************/
    // Forbidden calls
    /************************************************************************/
        TrafficLightEventConsumer( void ) = delete;
        DECLARE_NOCOPY_NOMOVE( TrafficLightEventConsumer );
    };

private:
//////////////////////////////////////////////////////////////////////////
// TrafficLightFSM::TrafficLightTimerConsumer class declaration
//////////////////////////////////////////////////////////////////////////
    friend class TrafficLightTimerConsumer;

    /**
     * \brief   TrafficLight state-machine timer consumer to dispatch the timer events. 
     **/
    class TrafficLightTimerConsumer : public IETimerConsumer
    {
    public:
        /**
         * \brief   Constructs and initializes TrafficLight Timer Consumer object.
         * \param   fsm     The instance of state-machine.
         **/
        TrafficLightTimerConsumer( TrafficLightFSM & fsm );

        virtual ~TrafficLightTimerConsumer( void ) = default;

    /************************************************************************/
    // Timer Consumer override
    /************************************************************************/
    private:
        /**
         * \brief   Process State Machine timers.
         **/
        virtual void processTimer( Timer & timer ) override;
    
    private:
    /************************************************************************/
    // Hidden member variables
    /************************************************************************/
        /**
         * \brief   The instance of TrafficLight state-mashine. 
         **/
        TrafficLightFSM &   mFsm;

    private:
    /************************************************************************/
    // Forbidden calls
    /************************************************************************/
        TrafficLightTimerConsumer( void ) = delete;
        DECLARE_NOCOPY_NOMOVE( TrafficLightTimerConsumer );
    };

//////////////////////////////////////////////////////////////////////////
// Predefined constants and types
//////////////////////////////////////////////////////////////////////////
private:
    /************************************************************************
     * \brief   TrafficLightFSM::eState
     *          The predefined states of TrafficLight State Machine.
     ************************************************************************/
    enum class eState
    {
          UNDEFINED

        , TRAFIC_LIGHT_OFF
        , TRAFFIC_LIGHT_ON
        , TRAFFIC_LIGHT_INITIALIZE
        , TRAFFIC_LIGHT_FUNCTION
        , TRAFFIC_LIGHT_YELLOW
        , TRAFFIC_LIGHT_RED
        , TRAFFIC_LIGHT_VEHICLE_RED
        , OPPOSIT_PEDESTRIAN_GREEN
        , TRAFFIC_LIGHT_GREEN
        , TRAFFIC_PEDESTRIAN_GREEN
        , TRAFFIC_VEHICLE_GREEN
        , TRAFFIC_LIGHT_START
   
        , STATE_SIZE
   };
   
    /**
     * \brief   Returns the string value of TrafficLight states.
     * \param   state   The state value of TrafficLight State Machine.
     **/
    static inline const char* const getString( const TrafficLightFSM::eState state );
    
//////////////////////////////////////////////////////////////////////////
// Constructor / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Instantiates and initializes FSM internals
     * \param   actionHandler   The reference of action handler object to trigger actions.
     * \param   instanceName    The name of FSM instance. By default it has the name of FSM. 
     **/
    TrafficLightFSM( IETrafficLightActionHandler & actionHandler, const std::string_view & instanceName = NETrafficLightFSM::InstanceDefaultName );

    /**
     * \brief   TrafficLightFSM class destructor
     **/
    ~TrafficLightFSM( void );

private:
    /**
     * \brief   Reference to State Machine action handler class object
     **/
    IETrafficLightActionHandler& mActionHandler;

public:

    /**
     * \brief   Initialize State Machine. Call before calling any trigger.
     * \param   ownerThread The pointer of master thread to process internal events and timers.
     **/
    void initFSM( DispatcherThread * ownerThread = nullptr );

    /**
     * \brief   Release State Machine. Call when complete working with FSM.
     **/
    void releaseFSM( void );

    /**
     * \brief   Call to send and event.
     * \param   fsmEventValue   The name of event, generated in NETrafficLightFSM namespace.
     **/
    inline void sendEvent( const NETrafficLightFSM::eFsmEventData data );   

//////////////////////////////////////////////////////////////////////////
// TrafficLight State Machine Triggers
//////////////////////////////////////////////////////////////////////////
public:

    /**
     * \brief   Triggered to power off the traffic light.
     *
     * \return  Returns true if trigger was processed in the current state, otherwise it returns false.
     * \remark  The method is not thread safe.
     **/
    bool powerOff( void );

    /**
     * \brief   Triggered to power on the traffic light.
     *
     * \return  Returns true if trigger was processed in the current state, otherwise it returns false.
     * \remark  The method is not thread safe.
     **/
    bool powerOn( void );

    /**
     * \brief   Triggered to start controlling the traffic light.
     *
     * \return  Returns true if trigger was processed in the current state, otherwise it returns false.
     * \remark  The method is not thread safe.
     **/
    bool startTrafficControl( void );

    /**
     * \brief   Triggered to stop the traffic light controller.
     *
     * \return  Returns true if trigger was processed in the current state, otherwise it returns false.
     * \remark  The method is not thread safe.
     **/
    bool stopTrafficControl( void );

//////////////////////////////////////////////////////////////////////////
// Get / Set attributes
//////////////////////////////////////////////////////////////////////////
public:

//////////////////////////////////////////////////////////////////////////
// Timer functions
//////////////////////////////////////////////////////////////////////////
public:
/************************************************************************/
// Timer attributes
/************************************************************************/

    /**
     * \brief   Returns true if specified timer object is active
     **/
     inline const bool isTimerActive( const NETrafficLightFSM::eFsmTimerData whichTimer ) const;

private:
/************************************************************************/
// Timer Triggers
/************************************************************************/

    /**
     * \brief   Timer Red object
     **/
    Timer     mTimerRed;
    /**
     * \brief   Timer Red trigger
     * \return  Returns true if timer was processed in the current state. Otherwise it returns false.
     **/
    bool onTimerRed( void );
    
    /**
     * \brief   Timer YellowRed object
     **/
    Timer     mTimerYellowRed;
    /**
     * \brief   Timer YellowRed trigger
     * \return  Returns true if timer was processed in the current state. Otherwise it returns false.
     **/
    bool onTimerYellowRed( void );
    
    /**
     * \brief   Timer Green object
     **/
    Timer     mTimerGreen;
    /**
     * \brief   Timer Green trigger
     * \return  Returns true if timer was processed in the current state. Otherwise it returns false.
     **/
    bool onTimerGreen( void );
    
    /**
     * \brief   Timer YellowGreen object
     **/
    Timer     mTimerYellowGreen;
    /**
     * \brief   Timer YellowGreen trigger
     * \return  Returns true if timer was processed in the current state. Otherwise it returns false.
     **/
    bool onTimerYellowGreen( void );
    
    /**
     * \brief   Timer PedestrianWalk object
     **/
    Timer     mTimerPedestrianWalk;
    /**
     * \brief   Timer PedestrianWalk trigger
     * \return  Returns true if timer was processed in the current state. Otherwise it returns false.
     **/
    bool onTimerPedestrianWalk( void );
    
    /**
     * \brief   Timer VehicleWait object
     **/
    Timer     mTimerVehicleWait;
    /**
     * \brief   Timer VehicleWait trigger
     * \return  Returns true if timer was processed in the current state. Otherwise it returns false.
     **/
    bool onTimerVehicleWait( void );
    
private:
/************************************************************************/
// Event Triggers
/************************************************************************/

    /**
     * \brief   Event StartTrafficLight trigger
     * \return  Returns true if event was processed in the current state. Otherwise it returns false.
     **/
    bool onEventStartTrafficLight( void );

//////////////////////////////////////////////////////////////////////////
// Hidden internal processing methods and attributes
//////////////////////////////////////////////////////////////////////////
private:
    /**
     * \brief   Returns true if trigger can start processing. If a trigger called from processing action, this will return false.
     * \param   triggerName The string name of trigger to process
     **/
    bool startProcessing( const char* const triggerName );

    /**
     * \brief   Called when complete processing trigger
     **/
    void endProcessing( void );

    /**
     * \brief   Called when entering next state
     * \param   curState    Value of current state
     * \param   nextState   Value of next state to enter
     * \param   nameTrigger The string name of currently processing trigger
     **/
    void enterState( const TrafficLightFSM::eState curState, const TrafficLightFSM::eState nextState, const char* const nameTrigger );

    /**
     * \brief   Called when leaving current state
     * \param   curState    Value of current state
     * \param   nextState   Value of next state to enter
     * \param   nameTrigger The string name of currently processing trigger
     **/
    void leaveState( const TrafficLightFSM::eState curState, const TrafficLightFSM::eState nextState, const char* const nameTrigger );

    /**
     * \brief   Called when updating state tree
     * \param   whichState  The value of state to update, including child states
     * \param   curState    The value of current state
     **/
    void updateStateTree( const TrafficLightFSM::eState whichState, const TrafficLightFSM::eState curState );

    /**
     * \brief   Returns true if specified state is in parent tree, e.g. if current state is in child sub-state tree.
     * \param   whichState  The state for checking, usually current state.
     * \param   checkState  The state to check.
     **/
    bool isInParentTree( TrafficLightFSM::eState whichState, const TrafficLightFSM::eState checkState );

    /**
     * \brief   Returns true if state machine is in operable state, i.e. it is not UNDEFINED
     **/
    inline bool isOperable( void ) const;

    /**
     * \brief   Returns the state machine object
     **/
    inline TrafficLightFSM & self( void );

//////////////////////////////////////////////////////////////////////////
// Standard internal member variables
//////////////////////////////////////////////////////////////////////////
private:
    
    /**
     * \brief   The name of State Machine.
     **/
    const String                mFsmName;
    /**
     * \brief   The master thread where event and timers should be processed. If nullptr, the current dispatcher value will be used.
     **/
    DispatcherThread *          mMasterThread;
    /**
     * \brief   The flag, indicating whether State Machine is currently processing trigger or not.
     **/
    bool                        mProcessing;
    /**
     * \brief   The current state of State Machine.
     **/
    eState                      mState;    
    /**
     * \brief   The TrafficLight state-machine event consumer.
     **/
    TrafficLightEventConsumer   mEventConsumer;
    /**
     * \brief   The TrafficLight timer event consumer.
     **/
    TrafficLightTimerConsumer   mTimerConsumer;
    /**
     * \brief   The array of state to indicate state changes. For parent state, this will indicate the current active child state
     **/
    eState                      mCurrentStates[static_cast<int>(eState::STATE_SIZE)]
    {
        /* UNDEFINED                 */   TrafficLightFSM::eState::UNDEFINED

        /* TRAFIC_LIGHT_OFF          */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_ON          */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_INITIALIZE  */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_FUNCTION    */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_YELLOW      */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_RED         */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_VEHICLE_RED */ , TrafficLightFSM::eState::UNDEFINED
        /* OPPOSIT_PEDESTRIAN_GREEN  */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_GREEN       */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_PEDESTRIAN_GREEN  */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_VEHICLE_GREEN     */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_START       */ , TrafficLightFSM::eState::UNDEFINED   

    };

//////////////////////////////////////////////////////////////////////////
// Static members. The tree structure of State Machine 
//////////////////////////////////////////////////////////////////////////
    /**
     * \brief   The fixed tree of parent states
     **/
    static constexpr    eState  sParrentStates[static_cast<int>(eState::STATE_SIZE)]
    {
        /* UNDEFINED                 */   TrafficLightFSM::eState::UNDEFINED

        /* TRAFIC_LIGHT_OFF          */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_ON          */ , TrafficLightFSM::eState::UNDEFINED
        /* TRAFFIC_LIGHT_INITIALIZE  */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_ON
        /* TRAFFIC_LIGHT_FUNCTION    */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_ON
        /* TRAFFIC_LIGHT_YELLOW      */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_FUNCTION
        /* TRAFFIC_LIGHT_RED         */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_FUNCTION
        /* TRAFFIC_LIGHT_VEHICLE_RED */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_RED
        /* OPPOSIT_PEDESTRIAN_GREEN  */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_RED
        /* TRAFFIC_LIGHT_GREEN       */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_FUNCTION
        /* TRAFFIC_PEDESTRIAN_GREEN  */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_GREEN
        /* TRAFFIC_VEHICLE_GREEN     */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_GREEN
        /* TRAFFIC_LIGHT_START       */ , TrafficLightFSM::eState::TRAFFIC_LIGHT_FUNCTION   
    };

    /**
     * \brief   The fixed tree of child states
     **/
    static constexpr    eState  sChildStates[static_cast<int>(eState::STATE_SIZE)]
{
    /* UNDEFINED                    */     TrafficLightFSM::eState::UNDEFINED

    /* TRAFIC_LIGHT_OFF             */   , TrafficLightFSM::eState::UNDEFINED
    /* TRAFFIC_LIGHT_ON             */   , TrafficLightFSM::eState::TRAFFIC_LIGHT_INITIALIZE
    /* TRAFFIC_LIGHT_INITIALIZE     */   , TrafficLightFSM::eState::UNDEFINED
    /* TRAFFIC_LIGHT_FUNCTION       */   , TrafficLightFSM::eState::TRAFFIC_LIGHT_START
    /* TRAFFIC_LIGHT_YELLOW         */   , TrafficLightFSM::eState::UNDEFINED
    /* TRAFFIC_LIGHT_RED            */   , TrafficLightFSM::eState::TRAFFIC_LIGHT_VEHICLE_RED
    /* TRAFFIC_LIGHT_VEHICLE_RED    */   , TrafficLightFSM::eState::UNDEFINED
    /* OPPOSIT_PEDESTRIAN_GREEN     */   , TrafficLightFSM::eState::UNDEFINED
    /* TRAFFIC_LIGHT_GREEN          */   , TrafficLightFSM::eState::TRAFFIC_PEDESTRIAN_GREEN
    /* TRAFFIC_PEDESTRIAN_GREEN     */   , TrafficLightFSM::eState::UNDEFINED
    /* TRAFFIC_VEHICLE_GREEN        */   , TrafficLightFSM::eState::UNDEFINED
    /* TRAFFIC_LIGHT_START          */   , TrafficLightFSM::eState::UNDEFINED
};
   
//////////////////////////////////////////////////////////////////////////
// Forbidden functions / methods call
//////////////////////////////////////////////////////////////////////////
private:
    TrafficLightFSM( void );
    TrafficLightFSM(const TrafficLightFSM & );
    const TrafficLightFSM& operator = (const TrafficLightFSM & );
};

//////////////////////////////////////////////////////////////////////////
// TrafficLightFSM class inline functions implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Get / Set inline attributes
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TrafficLightFSM class inline functions implementation
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   Returns true if state machine is in operable state, i.e. it is not UNDEFINED
 **/
inline bool TrafficLightFSM::isOperable( void ) const
{
    return (mState != TrafficLightFSM::eState::UNDEFINED);
}

/**
 * \brief   Returns the state machine object
 **/
inline TrafficLightFSM& TrafficLightFSM::self( void )
{
    return (*this);
}

inline const bool TrafficLightFSM::isTimerActive( const NETrafficLightFSM::eFsmTimerData whichTimer ) const
{
    switch (whichTimer)
    {
    case NETrafficLightFSM::eFsmTimerData::Red:
        return mTimerRed.isActive();
        
    case NETrafficLightFSM::eFsmTimerData::YellowRed:
        return mTimerYellowRed.isActive();
        
    case NETrafficLightFSM::eFsmTimerData::Green:
        return mTimerGreen.isActive();
        
    case NETrafficLightFSM::eFsmTimerData::YellowGreen:
        return mTimerYellowGreen.isActive();
        
    case NETrafficLightFSM::eFsmTimerData::PedestrianWalk:
        return mTimerPedestrianWalk.isActive();
        
    case NETrafficLightFSM::eFsmTimerData::VehicleWait:
        return mTimerVehicleWait.isActive();
        
    default:
        ASSERT(false);  // wrong timer ID.
        return false;
    }
}
/**
 * \brief   Sends FSM event to be processed. By default the Event is external
 **/
inline void TrafficLightFSM::sendEvent( const NETrafficLightFSM::eFsmEventData data )
{
    if (mMasterThread != nullptr )
        NETrafficLightFSM::FsmEvent::sendEvent(NETrafficLightFSM::FsmEventData( data ), static_cast<NETrafficLightFSM::IEFsmEventConsumer &>(mEventConsumer), *mMasterThread);
    else
        NETrafficLightFSM::FsmEvent::sendEvent(NETrafficLightFSM::FsmEventData( data ), static_cast<NETrafficLightFSM::IEFsmEventConsumer &>(mEventConsumer));
}
/**
 * \brief   Returns the string value of states
 **/
inline  const char* const TrafficLightFSM::getString( const TrafficLightFSM::eState state )
{
    switch (state)
    {
    case  TrafficLightFSM::eState::UNDEFINED:
        return "TrafficLightFSM::eState::UNDEFINED";

   case  TrafficLightFSM::eState::TRAFIC_LIGHT_OFF:
      return "TrafficLightFSM::eState::TRAFIC_LIGHT_OFF";

   case  TrafficLightFSM::eState::TRAFFIC_LIGHT_ON:
      return "TrafficLightFSM::eState::TRAFFIC_LIGHT_ON";

   case  TrafficLightFSM::eState::TRAFFIC_LIGHT_INITIALIZE:
      return "TrafficLightFSM::eState::TRAFFIC_LIGHT_INITIALIZE";

   case  TrafficLightFSM::eState::TRAFFIC_LIGHT_FUNCTION:
      return "TrafficLightFSM::eState::TRAFFIC_LIGHT_FUNCTION";

   case  TrafficLightFSM::eState::TRAFFIC_LIGHT_YELLOW:
      return "TrafficLightFSM::eState::TRAFFIC_LIGHT_YELLOW";

   case  TrafficLightFSM::eState::TRAFFIC_LIGHT_RED:
      return "TrafficLightFSM::eState::TRAFFIC_LIGHT_RED";

   case  TrafficLightFSM::eState::TRAFFIC_LIGHT_VEHICLE_RED:
      return "TrafficLightFSM::eState::TRAFFIC_LIGHT_VEHICLE_RED";

   case  TrafficLightFSM::eState::OPPOSIT_PEDESTRIAN_GREEN:
      return "TrafficLightFSM::eState::OPPOSIT_PEDESTRIAN_GREEN";

   case  TrafficLightFSM::eState::TRAFFIC_LIGHT_GREEN:
      return "TrafficLightFSM::eState::TRAFFIC_LIGHT_GREEN";

   case  TrafficLightFSM::eState::TRAFFIC_PEDESTRIAN_GREEN:
      return "TrafficLightFSM::eState::TRAFFIC_PEDESTRIAN_GREEN";

   case  TrafficLightFSM::eState::TRAFFIC_VEHICLE_GREEN:
      return "TrafficLightFSM::eState::TRAFFIC_VEHICLE_GREEN";

   case  TrafficLightFSM::eState::TRAFFIC_LIGHT_START:
      return "TrafficLightFSM::eState::TRAFFIC_LIGHT_START";

    case  TrafficLightFSM::eState::STATE_SIZE: // fall through
    default:
        ASSERT(false);        
        return "ERR: Unexpected TrafficLightFSM::eState value!";
   }
}

//////////////////////////////////////////////////////////////////////////
// End generate TrafficLightFSM.hpp file
//////////////////////////////////////////////////////////////////////////
