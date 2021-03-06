#ifndef OPENMITTSU_MESSAGES_CONTACT_CONTACTENCRYPTEDFILEANDIMAGEIDANDKEYMESSAGECONTENT_H_
#define OPENMITTSU_MESSAGES_CONTACT_CONTACTENCRYPTEDFILEANDIMAGEIDANDKEYMESSAGECONTENT_H_

#include "src/messages/contact/ContactMessageContent.h"
#include "src/crypto/EncryptionKey.h"

#include <QByteArray>

namespace openmittsu {
	namespace messages {
		namespace contact {

			class ContactEncryptedFileAndImageIdAndKeyMessageContent : public ContactMessageContent {
			public:
				ContactEncryptedFileAndImageIdAndKeyMessageContent(QByteArray const& encryptedFile, QByteArray const& imageBlobId, openmittsu::crypto::EncryptionKey const& encryptionKey, QString const& mimeType, QString const& fileName, QString const& caption, quint64 fileSizeInBytes);
				virtual ~ContactEncryptedFileAndImageIdAndKeyMessageContent();

				virtual ContactMessageContent* clone() const override;

				virtual bool hasPreSendCallbackTask() const override;
				virtual openmittsu::tasks::CallbackTask* getPreSendCallbackTask(Message* message, std::shared_ptr<openmittsu::acknowledgments::AcknowledgmentProcessor> const& acknowledgmentProcessor, std::shared_ptr<openmittsu::network::ServerConfiguration> const& serverConfiguration, std::shared_ptr<openmittsu::crypto::FullCryptoBox> const& cryptoBox) const override;

				virtual bool hasPostReceiveCallbackTask() const override;
				virtual openmittsu::tasks::CallbackTask* getPostReceiveCallbackTask(Message* message, std::shared_ptr<openmittsu::network::ServerConfiguration> const& serverConfiguration, std::shared_ptr<openmittsu::crypto::FullCryptoBox> const& cryptoBox) const override;

				virtual MessageContent* integrateCallbackTaskResult(openmittsu::tasks::CallbackTask const* callbackTask) const override;

				virtual QByteArray toPacketPayload() const override;
				virtual MessageContent* fromPacketPayload(FullMessageHeader const& messageHeader, QByteArray const& payload) const override;

				QByteArray const& getEncryptedFileData() const;
				QByteArray const& getImageBlobId() const;
				openmittsu::crypto::EncryptionKey const& getEncryptionKey() const;
				QString const& getMimeType() const;
				QString const& getFileName() const;
				QString const& getCaption() const;
				quint64 getFileSizeInBytes() const;
			private:
				QByteArray const m_encryptedFileData;
				QByteArray const m_imageBlobId;
				openmittsu::crypto::EncryptionKey const m_encryptionKey;
				QString const m_mimeType;
				QString const m_fileName;
				QString const m_caption;
				quint64 const m_fileSizeInBytes;
			};

		}
	}
}

#endif // OPENMITTSU_MESSAGES_CONTACT_CONTACTENCRYPTEDFILEANDIMAGEIDANDKEYMESSAGECONTENT_H_
