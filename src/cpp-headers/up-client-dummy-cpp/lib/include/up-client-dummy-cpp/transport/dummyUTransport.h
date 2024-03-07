#ifndef UP_CLIENT_DUMMY_CPP_DUMMYUTRANSPORT_H
#define UP_CLIENT_DUMMY_CPP_DUMMYUTRANSPORT_H

#include <up-cpp/transport/UTransport.h>

#include <memory>

using namespace uprotocol::v1;
using namespace uprotocol::utransport;

class DummyUTransport : public UTransport {

    DummyUTransport() {
        // do nothing :)
    }

    /**
    * Transmit UPayload to the topic using the attributes defined in UTransportAttributes.
    * @param topic Resolved UUri topic to send the payload to.
    * @param payload Actual payload.
    * @param attributes Additional transport attributes.
    * @return Returns OKSTATUS if the payload has been successfully sent (ACK'ed), otherwise it
    * returns FAILSTATUS with the appropriate failure.
    */
    UStatus send(const UUri &uri,
                 const UPayload &payload,
                 const UAttributes &attributes) noexcept;

    /**
    * Register listener to be called when UPayload is received for the specific topic.
    * @param topic Resolved UUri for where the message arrived via the underlying transport technology.
    * @param listener The method to execute to process the date for the topic.
    * @return Returns OKSTATUS if the listener is unregistered correctly, otherwise it returns FAILSTATUS
    * with the appropriate failure.
    */
    UStatus registerListener(const UUri &uri,
                             const UListener &listener) noexcept;

    /**
    * Unregister a listener for a given topic. Messages arriving on this topic will no longer be processed
    * by this listener.
    * @param topic Resolved UUri for where the listener was registered to receive messages from.
    * @param listener The method to execute to process the date for the topic.
    * @return Returns OKSTATUS if the listener is unregistered correctly, otherwise it returns FAILSTATUS
    * with the appropriate failure.
    */
    UStatus unregisterListener(const UUri &uri,
                               const UListener &listener) noexcept;

    UStatus receive(const UUri &uri,
                    const UPayload &payload,
                    const UAttributes &attributes) noexcept;
};

std::unique_ptr<DummyUTransport> new_dummy_utransport();

#endif //UP_CLIENT_DUMMY_CPP_DUMMYUTRANSPORT_H
