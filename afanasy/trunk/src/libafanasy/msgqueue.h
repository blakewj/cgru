#pragma once

#include "afqueue.h"
#include "msg.h"

namespace af
{

/// Simple FIFO message queue
class MsgQueue : public AfQueue
{
public:
   MsgQueue( const std::string & QueueName, bool i_start_thread=true );
   virtual ~MsgQueue();

/// Return first message from queue. BLOCKING FUNCTION if \c block==AfQueue::e_wait.
   inline Msg* popMsg( WaitMode i_block ) { return (Msg*)pop(i_block);}

/// Push message to queue back.
   inline bool pushMsg( Msg* msg) { if(msg) msg->resetWrittenSize(); return push( msg);}

protected:
   void processItem( AfQueueItem* item);

private:
   void send( const Msg * msg, const Address & address) const;
};

} // namespace af