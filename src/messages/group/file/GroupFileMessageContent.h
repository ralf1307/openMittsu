#ifndef OPENMITTSU_MESSAGES_GROUP_GROUPFILEMESSAGECONTENT_H_
#define OPENMITTSU_MESSAGES_GROUP_GROUPFILEMESSAGECONTENT_H_

#include "src/messages/group/GroupMessageContent.h"

#include <QByteArray>

namespace openmittsu {
	namespace messages {
		namespace group {

			class GroupFileMessageContent : public GroupMessageContent {
			public:
				GroupFileMessageContent(openmittsu::protocol::GroupId const& groupId, QByteArray const& file, QByteArray const& image, QString const& mimeType, QString const& fileName, QString const& caption, quint64 fileSizeInBytes);
				virtual ~GroupFileMessageContent();

				virtual GroupMessageContent* clone() const override;

				virtual bool hasPreSendCallbackTask() const override;

				virtual openmittsu::tasks::CallbackTask* getPreSendCallbackTask(Message* message, std::shared_ptr<openmittsu::acknowledgments::AcknowledgmentProcessor> const& acknowledgmentProcessor, std::shared_ptr<openmittsu::network::ServerConfiguration> const& serverConfiguration, std::shared_ptr<openmittsu::crypto::FullCryptoBox> const& cryptoBox) const override;
				virtual MessageContent* integrateCallbackTaskResult(openmittsu::tasks::CallbackTask const* callbackTask) const override;

				virtual QByteArray toPacketPayload() const override;
				virtual MessageContent* fromPacketPayload(FullMessageHeader const& messageHeader, QByteArray const& payload) const override;

				QByteArray const& getFileData() const;
				QByteArray const& getImageData() const;
				QString const& getMimeType() const;
				QString const& getFileName() const;
				QString const& getCaption() const;
				quint64 getFileSizeInBytes() const;
			private:
				QByteArray const m_fileData;
				QByteArray const m_imageData;
				QString const m_mimeType;
				QString const m_fileName;
				QString const m_caption;
				quint64 const m_fileSizeInBytes;

				static bool m_registrationResult;
			};

		}
	}
}

#endif // OPENMITTSU_MESSAGES_GROUP_GROUPFILEMESSAGECONTENT_H_
