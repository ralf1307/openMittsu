#ifndef OPENMITTSU_OPTIONS_OPTIONS_H_
#define OPENMITTSU_OPTIONS_OPTIONS_H_

#include <QMetaType>
#include <QHash>

namespace openmittsu {
	namespace options {
		enum class Options {
			BOOLEAN_SEND_TYPING_NOTIFICATION,
			BOOLEAN_SEND_READ_NOTIFICATION,
			BOOLEAN_FORCE_FOREGROUND_ON_MESSAGE_RECEIVED,
			BOOLEAN_PLAY_SOUND_ON_MESSAGE_RECEIVED,
			BOOLEAN_BLINK_ICON_ON_MESSAGE_RECEIVED,
			BOOLEAN_NOTIFICATION_ON_MESSAGE_RECEIVED,
			BOOLEAN_RECONNECT_ON_CONNECTION_LOSS,
			BOOLEAN_UPDATE_FEATURE_LEVEL,
			BOOLEAN_TRUST_OTHERS,
			BOOLEAN_IGNORE_LEGACY_CONTACTS_DATABASE,
			BOOLEAN_MINIMIZE_TO_TRAY,
			FILEPATH_DATABASE,
			FILEPATH_LEGACY_CLIENT_CONFIGURATION,
			FILEPATH_LEGACY_CONTACTS_DATABASE,
			BINARY_MAINWINDOW_GEOMETRY,
			BINARY_MAINWINDOW_STATE
		};

		uint qHash(openmittsu::options::Options const& key, uint seed);
	}
}

Q_DECLARE_METATYPE(openmittsu::options::Options)

#endif // OPENMITTSU_OPTIONS_OPTIONS_H_
