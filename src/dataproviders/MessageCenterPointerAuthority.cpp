#include "src/dataproviders/MessageCenterPointerAuthority.h"

#include "src/exceptions/InternalErrorException.h"
#include "src/utility/Logging.h"
#include "src/utility/QObjectConnectionMacro.h"

#include "src/dataproviders/MessageCenterWrapperFactory.h"

namespace openmittsu {
	namespace dataproviders {

		MessageCenterPointerAuthority::MessageCenterPointerAuthority() : QObject() {
			//
		}

		MessageCenterPointerAuthority::~MessageCenterPointerAuthority() {
			//
		}

		void MessageCenterPointerAuthority::setMessageCenter(std::shared_ptr<MessageCenter> newMessageCenter) {
			m_messageCenter = newMessageCenter;

			emit newMessageCenterAvailable();
		}

		std::weak_ptr<MessageCenter> MessageCenterPointerAuthority::getMessageCenterWeak() const {
			if (!m_messageCenter) {
				LOGGER()->error("The MessageCenter in this authority was NULL, but a weak reference was requested!");
			}
			return m_messageCenter;
		}

		std::shared_ptr<MessageCenter> MessageCenterPointerAuthority::getMessageCenterStrong() const {
			if (!m_messageCenter) {
				LOGGER()->error("The MessageCenter in this authority was NULL, but a strong reference was requested!");
			}
			return m_messageCenter;
		}

		MessageCenterWrapperFactory MessageCenterPointerAuthority::getMessageCenterWrapperFactory() const {
			return MessageCenterWrapperFactory(*this);
		}

	}
}