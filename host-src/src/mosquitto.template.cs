using System;
using System.InterOpServices;

public class Mosquitto {

    /* Enum: mqtt311_connack_codes
     *
     * The CONNACK results for MQTT v3.1.1, and v3.1.
     *
     * Values:
     *  CONNACK_ACCEPTED - 0
     *  CONNACK_REFUSED_PROTOCOL_VERSION - 1
     *  CONNACK_REFUSED_IDENTIFIER_REJECTED - 2
     *  CONNACK_REFUSED_SERVER_UNAVAILABLE - 3
     *  CONNACK_REFUSED_BAD_USERNAME_PASSWORD - 4
     *  CONNACK_REFUSED_NOT_AUTHORIZED - 5
     */
    public static enum mqtt311_connack_codes : int {
	    CONNACK_ACCEPTED = 0,
	    CONNACK_REFUSED_PROTOCOL_VERSION = 1,
	    CONNACK_REFUSED_IDENTIFIER_REJECTED = 2,
	    CONNACK_REFUSED_SERVER_UNAVAILABLE = 3,
	    CONNACK_REFUSED_BAD_USERNAME_PASSWORD = 4,
	    CONNACK_REFUSED_NOT_AUTHORIZED = 5,
    }

    /* Enum: mqtt5_return_codes
     * The reason codes returned in various MQTT commands.
     *
     * Values:
     *  MQTT_RC_SUCCESS - 0
     *  MQTT_RC_NORMAL_DISCONNECTION - 0
     *  MQTT_RC_GRANTED_QOS0 - 0
     *  MQTT_RC_GRANTED_QOS1 - 1
     *  MQTT_RC_GRANTED_QOS2 - 2
     *  MQTT_RC_DISCONNECT_WITH_WILL_MSG - 4
     *  MQTT_RC_NO_MATCHING_SUBSCRIBERS - 16
     *  MQTT_RC_NO_SUBSCRIPTION_EXISTED - 17
     *  MQTT_RC_CONTINUE_AUTHENTICATION - 24
     *  MQTT_RC_REAUTHENTICATE - 25
     *  MQTT_RC_UNSPECIFIED - 128
     *  MQTT_RC_MALFORMED_PACKET - 129
     *  MQTT_RC_PROTOCOL_ERROR - 130
     *  MQTT_RC_IMPLEMENTATION_SPECIFIC - 131
     *  MQTT_RC_UNSUPPORTED_PROTOCOL_VERSION - 132
     *  MQTT_RC_CLIENTID_NOT_VALID - 133
     *  MQTT_RC_BAD_USERNAME_OR_PASSWORD - 134
     *  MQTT_RC_NOT_AUTHORIZED - 135
     *  MQTT_RC_SERVER_UNAVAILABLE - 136
     *  MQTT_RC_SERVER_BUSY - 137
     *  MQTT_RC_BANNED - 138
     *  MQTT_RC_SERVER_SHUTTING_DOWN - 139
     *  MQTT_RC_BAD_AUTHENTICATION_METHOD - 140
     *  MQTT_RC_KEEP_ALIVE_TIMEOUT - 141
     *  MQTT_RC_SESSION_TAKEN_OVER - 142
     *  MQTT_RC_TOPIC_FILTER_INVALID - 143
     *  MQTT_RC_TOPIC_NAME_INVALID - 144
     *  MQTT_RC_PACKET_ID_IN_USE - 145
     *  MQTT_RC_PACKET_ID_NOT_FOUND - 146
     *  MQTT_RC_RECEIVE_MAXIMUM_EXCEEDED - 147
     *  MQTT_RC_TOPIC_ALIAS_INVALID - 148
     *  MQTT_RC_PACKET_TOO_LARGE - 149
     *  MQTT_RC_MESSAGE_RATE_TOO_HIGH - 150
     *  MQTT_RC_QUOTA_EXCEEDED - 151
     *  MQTT_RC_ADMINISTRATIVE_ACTION - 152
     *  MQTT_RC_PAYLOAD_FORMAT_INVALID - 153
     *  MQTT_RC_RETAIN_NOT_SUPPORTED - 154
     *  MQTT_RC_QOS_NOT_SUPPORTED - 155
     *  MQTT_RC_USE_ANOTHER_SERVER - 156
     *  MQTT_RC_SERVER_MOVED - 157
     *  MQTT_RC_SHARED_SUBS_NOT_SUPPORTED - 158
     *  MQTT_RC_CONNECTION_RATE_EXCEEDED - 159
     *  MQTT_RC_MAXIMUM_CONNECT_TIME - 160
     *  MQTT_RC_SUBSCRIPTION_IDS_NOT_SUPPORTED - 161
     *  MQTT_RC_WILDCARD_SUBS_NOT_SUPPORTED - 162
     */
    public static enum mqtt5_return_codes : int {
        MQTT_RC_SUCCESS	= 0,
        MQTT_RC_NORMAL_DISCONNECTION = 0,
        MQTT_RC_GRANTED_QOS0 = 0,
        MQTT_RC_GRANTED_QOS1 = 1,
        MQTT_RC_GRANTED_QOS2 = 2,
        MQTT_RC_DISCONNECT_WITH_WILL_MSG = 4,
        MQTT_RC_NO_MATCHING_SUBSCRIBERS = 16,
        MQTT_RC_NO_SUBSCRIPTION_EXISTED = 17,
        MQTT_RC_CONTINUE_AUTHENTICATION = 24,
        MQTT_RC_REAUTHENTICATE = 25,
        MQTT_RC_UNSPECIFIED = 128,
        MQTT_RC_MALFORMED_PACKET = 129,
        MQTT_RC_PROTOCOL_ERROR = 130,
        MQTT_RC_IMPLEMENTATION_SPECIFIC = 131,
        MQTT_RC_UNSUPPORTED_PROTOCOL_VERSION = 132,
        MQTT_RC_CLIENTID_NOT_VALID = 133,
        MQTT_RC_BAD_USERNAME_OR_PASSWORD = 134,
        MQTT_RC_NOT_AUTHORIZED = 135,
        MQTT_RC_SERVER_UNAVAILABLE = 136,
        MQTT_RC_SERVER_BUSY = 137,
        MQTT_RC_BANNED = 138,
        MQTT_RC_SERVER_SHUTTING_DOWN = 139,
        MQTT_RC_BAD_AUTHENTICATION_METHOD = 140,
        MQTT_RC_KEEP_ALIVE_TIMEOUT = 141,
        MQTT_RC_SESSION_TAKEN_OVER = 142,
        MQTT_RC_TOPIC_FILTER_INVALID = 143,
        MQTT_RC_TOPIC_NAME_INVALID = 144,
        MQTT_RC_PACKET_ID_IN_USE = 145,
        MQTT_RC_PACKET_ID_NOT_FOUND = 146,
        MQTT_RC_RECEIVE_MAXIMUM_EXCEEDED = 147,
        MQTT_RC_TOPIC_ALIAS_INVALID = 148,
        MQTT_RC_PACKET_TOO_LARGE = 149,
        MQTT_RC_MESSAGE_RATE_TOO_HIGH = 150,
        MQTT_RC_QUOTA_EXCEEDED = 151,
        MQTT_RC_ADMINISTRATIVE_ACTION = 152,
        MQTT_RC_PAYLOAD_FORMAT_INVALID = 153,
        MQTT_RC_RETAIN_NOT_SUPPORTED = 154,
        MQTT_RC_QOS_NOT_SUPPORTED = 155,
        MQTT_RC_USE_ANOTHER_SERVER = 156,
        MQTT_RC_SERVER_MOVED = 157,
        MQTT_RC_SHARED_SUBS_NOT_SUPPORTED = 158,
        MQTT_RC_CONNECTION_RATE_EXCEEDED = 159,
        MQTT_RC_MAXIMUM_CONNECT_TIME = 160,
        MQTT_RC_SUBSCRIPTION_IDS_NOT_SUPPORTED = 161,
        MQTT_RC_WILDCARD_SUBS_NOT_SUPPORTED = 162
    }

    /* Enum: mqtt5_property
     * Options for use with MQTTv5 properties.
     * Options:
     *
     *	MQTT_PROP_PAYLOAD_FORMAT_INDICATOR - property option.
     *	MQTT_PROP_MESSAGE_EXPIRY_INTERVAL - property option.
     *	MQTT_PROP_CONTENT_TYPE - property option.
     *	MQTT_PROP_RESPONSE_TOPIC - property option.
     *	MQTT_PROP_CORRELATION_DATA - property option.
     *	MQTT_PROP_SUBSCRIPTION_IDENTIFIER - property option.
     *	MQTT_PROP_SESSION_EXPIRY_INTERVAL - property option.
     *	MQTT_PROP_ASSIGNED_CLIENT_IDENTIFIER - property option.
     *	MQTT_PROP_SERVER_KEEP_ALIVE - property option.
     *	MQTT_PROP_AUTHENTICATION_METHOD - property option.
     *	MQTT_PROP_AUTHENTICATION_DATA - property option.
     *	MQTT_PROP_REQUEST_PROBLEM_INFORMATION - property option.
     *	MQTT_PROP_WILL_DELAY_INTERVAL - property option.
     *	MQTT_PROP_REQUEST_RESPONSE_INFORMATION - property option.
     *	MQTT_PROP_RESPONSE_INFORMATION - property option.
     *	MQTT_PROP_SERVER_REFERENCE - property option.
     *	MQTT_PROP_REASON_STRING - property option.
     *	MQTT_PROP_RECEIVE_MAXIMUM - property option.
     *	MQTT_PROP_TOPIC_ALIAS_MAXIMUM - property option.
     *	MQTT_PROP_TOPIC_ALIAS - property option.
     *	MQTT_PROP_MAXIMUM_QOS - property option.
     *	MQTT_PROP_RETAIN_AVAILABLE - property option.
     *	MQTT_PROP_USER_PROPERTY - property option.
     *	MQTT_PROP_MAXIMUM_PACKET_SIZE - property option.
     *	MQTT_PROP_WILDCARD_SUB_AVAILABLE - property option.
     *	MQTT_PROP_SUBSCRIPTION_ID_AVAILABLE - property option.
     *	MQTT_PROP_SHARED_SUB_AVAILABLE - property option.
     */
    public static enum mqtt5_property : int {
        MQTT_PROP_PAYLOAD_FORMAT_INDICATOR = 1,		/* Byte :				PUBLISH, Will Properties */
	    MQTT_PROP_MESSAGE_EXPIRY_INTERVAL = 2,		/* 4 byte int :			PUBLISH, Will Properties */
	    MQTT_PROP_CONTENT_TYPE = 3,					/* UTF-8 string :		PUBLISH, Will Properties */
	    MQTT_PROP_RESPONSE_TOPIC = 8,				/* UTF-8 string :		PUBLISH, Will Properties */
	    MQTT_PROP_CORRELATION_DATA = 9,				/* Binary Data :		PUBLISH, Will Properties */
	    MQTT_PROP_SUBSCRIPTION_IDENTIFIER = 11,		/* Variable byte int :	PUBLISH, SUBSCRIBE */
	    MQTT_PROP_SESSION_EXPIRY_INTERVAL = 17,		/* 4 byte int :			CONNECT, CONNACK, DISCONNECT */
	    MQTT_PROP_ASSIGNED_CLIENT_IDENTIFIER = 18,	/* UTF-8 string :		CONNACK */
    	MQTT_PROP_SERVER_KEEP_ALIVE = 19,			/* 2 byte int :			CONNACK */
	    MQTT_PROP_AUTHENTICATION_METHOD = 21,		/* UTF-8 string :		CONNECT, CONNACK, AUTH */
	    MQTT_PROP_AUTHENTICATION_DATA = 22,			/* Binary Data :		CONNECT, CONNACK, AUTH */
	    MQTT_PROP_REQUEST_PROBLEM_INFORMATION = 23,	/* Byte :				CONNECT */
	    MQTT_PROP_WILL_DELAY_INTERVAL = 24,			/* 4 byte int :			Will properties */
	    MQTT_PROP_REQUEST_RESPONSE_INFORMATION = 25,/* Byte :				CONNECT */
	    MQTT_PROP_RESPONSE_INFORMATION = 26,		/* UTF-8 string :		CONNACK */
	    MQTT_PROP_SERVER_REFERENCE = 28,			/* UTF-8 string :		CONNACK, DISCONNECT */
	    MQTT_PROP_REASON_STRING = 31,				/* UTF-8 string :		All except Will properties */
	    MQTT_PROP_RECEIVE_MAXIMUM = 33,				/* 2 byte int :			CONNECT, CONNACK */
	    MQTT_PROP_TOPIC_ALIAS_MAXIMUM = 34,			/* 2 byte int :			CONNECT, CONNACK */
    	MQTT_PROP_TOPIC_ALIAS = 35,					/* 2 byte int :			PUBLISH */
    	MQTT_PROP_MAXIMUM_QOS = 36,					/* Byte :				CONNACK */
	    MQTT_PROP_RETAIN_AVAILABLE = 37,			/* Byte :				CONNACK */
	    MQTT_PROP_USER_PROPERTY = 38,				/* UTF-8 string pair :	All */
	    MQTT_PROP_MAXIMUM_PACKET_SIZE = 39,			/* 4 byte int :			CONNECT, CONNACK */
	    MQTT_PROP_WILDCARD_SUB_AVAILABLE = 40,		/* Byte :				CONNACK */
	    MQTT_PROP_SUBSCRIPTION_ID_AVAILABLE = 41,	/* Byte :				CONNACK */
	    MQTT_PROP_SHARED_SUB_AVAILABLE = 42,		/* Byte :				CONNACK */
    }

    public static enum mqtt5_property_type : int {
	    MQTT_PROP_TYPE_BYTE = 1,
	    MQTT_PROP_TYPE_INT16 = 2,
	    MQTT_PROP_TYPE_INT32 = 3,
	    MQTT_PROP_TYPE_VARINT = 4,
	    MQTT_PROP_TYPE_BINARY = 5,
	    MQTT_PROP_TYPE_STRING = 6,
	    MQTT_PROP_TYPE_STRING_PAIR = 7
    }

    /* Enum: mqtt5_sub_options
     * Options for use with MQTTv5 subscriptions.
     *
     * MQTT_SUB_OPT_NO_LOCAL - with this option set, if this client publishes to
     * a topic to which it is subscribed, the broker will not publish the
     * message back to the client.
     *
     * MQTT_SUB_OPT_RETAIN_AS_PUBLISHED - with this option set, messages
     * published for this subscription will keep the retain flag as was set by
     * the publishing client. The default behaviour without this option set has
     * the retain flag indicating whether a message is fresh/stale.
     *
     * MQTT_SUB_OPT_SEND_RETAIN_ALWAYS - with this option set, pre-existing
     * retained messages are sent as soon as the subscription is made, even
     * if the subscription already exists. This is the default behaviour, so
     * it is not necessary to set this option.
     *
     * MQTT_SUB_OPT_SEND_RETAIN_NEW - with this option set, pre-existing retained
     * messages for this subscription will be sent when the subscription is made,
     * but only if the subscription does not already exist.
     *
     * MQTT_SUB_OPT_SEND_RETAIN_NEVER - with this option set, pre-existing
     * retained messages will never be sent for this subscription.
     */
    public static enum mqtt5_sub_options : int {
	    MQTT_SUB_OPT_NO_LOCAL = 0x04,
	    MQTT_SUB_OPT_RETAIN_AS_PUBLISHED = 0x08,
	    MQTT_SUB_OPT_SEND_RETAIN_ALWAYS = 0x00,
	    MQTT_SUB_OPT_SEND_RETAIN_NEW = 0x10,
	    MQTT_SUB_OPT_SEND_RETAIN_NEVER = 0x20,
    }

    /*
     * Log types.
     */
    public static enum log_types : UInt32 {
        MOSQ_LOG_NONE = 0,
        MOSQ_LOG_INFO = 1,
        MOSQ_LOG_NOTICE = 2,
        MOSQ_LOG_WARNING = 4,
        MOSQ_LOG_ERR = 8,
        MOSQ_LOG_DEBUG = 16,
        MOSQ_LOG_SUBSCRIBE = 32,
        MOSQ_LOG_UNSUBSCRIBE = 64,
        MOSQ_LOG_WEBSOCKETS = 128,
        MOSQ_LOG_INTERNAL = 0x80000000U,
        MOSQ_LOG_ALL = 0xffffffffU
    }

    /* Error values */
    public static enum mosq_err_t : int {
    	MOSQ_ERR_AUTH_CONTINUE = -4,
	    MOSQ_ERR_NO_SUBSCRIBERS = -3,
	    MOSQ_ERR_SUB_EXISTS = -2,
	    MOSQ_ERR_CONN_PENDING = -1,
	    MOSQ_ERR_SUCCESS = 0,
	    MOSQ_ERR_NOMEM = 1,
	    MOSQ_ERR_PROTOCOL = 2,
	    MOSQ_ERR_INVAL = 3,
	    MOSQ_ERR_NO_CONN = 4,
	    MOSQ_ERR_CONN_REFUSED = 5,
    	MOSQ_ERR_NOT_FOUND = 6,
	    MOSQ_ERR_CONN_LOST = 7,
	    MOSQ_ERR_TLS = 8,
	    MOSQ_ERR_PAYLOAD_SIZE = 9,
	    MOSQ_ERR_NOT_SUPPORTED = 10,
	    MOSQ_ERR_AUTH = 11,
	    MOSQ_ERR_ACL_DENIED = 12,
	    MOSQ_ERR_UNKNOWN = 13,
	    MOSQ_ERR_ERRNO = 14,
	    MOSQ_ERR_EAI = 15,
	    MOSQ_ERR_PROXY = 16,
	    MOSQ_ERR_PLUGIN_DEFER = 17,
	    MOSQ_ERR_MALFORMED_UTF8 = 18,
	    MOSQ_ERR_KEEPALIVE = 19,
	    MOSQ_ERR_LOOKUP = 20,
	    MOSQ_ERR_MALFORMED_PACKET = 21,
	    MOSQ_ERR_DUPLICATE_PROPERTY = 22,
	    MOSQ_ERR_TLS_HANDSHAKE = 23,
	    MOSQ_ERR_QOS_NOT_SUPPORTED = 24,
	    MOSQ_ERR_OVERSIZE_PACKET = 25,
	    MOSQ_ERR_OCSP = 26,
	    MOSQ_ERR_TIMEOUT = 27,
	    MOSQ_ERR_RETAIN_NOT_SUPPORTED = 28,
	    MOSQ_ERR_TOPIC_ALIAS_INVALID = 29,
	    MOSQ_ERR_ADMINISTRATIVE_ACTION = 30,
	    MOSQ_ERR_ALREADY_EXISTS = 31,
    }

    /* Option values */
    public static enum mosq_opt_t : int {
    	MOSQ_OPT_PROTOCOL_VERSION = 1,
    	MOSQ_OPT_SSL_CTX = 2,
    	MOSQ_OPT_SSL_CTX_WITH_DEFAULTS = 3,
	    MOSQ_OPT_RECEIVE_MAXIMUM = 4,
	    MOSQ_OPT_SEND_MAXIMUM = 5,
    	MOSQ_OPT_TLS_KEYFORM = 6,
	    MOSQ_OPT_TLS_ENGINE = 7,
	    MOSQ_OPT_TLS_ENGINE_KPASS_SHA1 = 8,
	    MOSQ_OPT_TLS_OCSP_REQUIRED = 9,
	    MOSQ_OPT_TLS_ALPN = 10,
	    MOSQ_OPT_TCP_NODELAY = 11,
	    MOSQ_OPT_BIND_ADDRESS = 12,
	    MOSQ_OPT_TLS_USE_OS_CERTS = 13,
    }

    public static const int MOSQ_MQTT_ID_MAX_LENGTH = 23;

    /*
     * Protocol types.
     */
    public static enum mosq_protocol_t : int {
        MQTT_PROTOCOL_V31 = 3,
        MQTT_PROTOCOL_V311 = 4,
        MQTT_PROTOCOL_V5 = 5
    }

    [StructLayout(Layout.Sequential)]
    public static struct mosquitto_message {
	    int mid;
	    char[] topic;
	    IntPtr payload;
	    int payloadlen;
	    int qos;
	    bool retain;
    }

    [DllImport(${LIB_MOSQUITTO})]
    public static extern int mosquitto_lib_version(ref int major, ref int minor, ref int revision);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_lib_init(void);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_lib_cleanup(void);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern IntPtr mosquitto_new(char[] id, bool clean_session, IntPtr obj);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern void mosquitto_destroy(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_reinitialize(IntPtr mosq, char[] id, bool clean_session, IntPtr obj);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_will_set(IntPtr mosq, char[] topic, int payloadlen, IntPtr payload, int qos, bool retain);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_will_set_v5(IntPtr mosq, char[] topic, int payloadlen, IntPtr payload,
                                                          int qos, bool retain, IntPtr properties);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_will_clear(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_username_pw_set(IntPtr mosq, char[] username, char[] password);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_connect(IntPtr mosq, char[] host, int port, int keepalive);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_connect_bind(IntPtr mosq, char[] host, int port, int keepalive, char[] bindaddress);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_connect_bind_v5(IntPtr mosq, char[] host, int port, int keepalive,
                                                              char[] bindaddress, IntPtr properties);
    
    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_connect_async(IntPtr mosq, char[] host, int port, int keepalive);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_connect_bind_async(IntPtr mosq, char[] host, int port, int keepalive, char[] bindaddress);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_connect_srv(IntPtr mosq, char[] host, int keepalive, char[] bindaddress);
    
    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_reconnect(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_reconnect_async(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_disconnect(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_disconnect_v5(IntPtr mosq, int reason, IntPtr properties);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_publish(IntPtr mosq, ref int mid, char[] topic, int payloadlen, IntPtr payload, int qos, bool retain);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_publish_v5(IntPtr mosq, ref int mid, char[] topic, int payloadlen,
                                                         IntPtr payload, int qos, bool retain, IntPtr properties);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_subscribe(IntPtr mosq, ref int mid, char[] pattern, int qos);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_subscribe_v5(IntPtr mosq, ref int mid, char[] pattern, int qos,
                                                           mqtt5_sub_options options, IntPtr properties);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_subscribe_multiple(IntPtr mosq, ref int mid, int sub_count, 
                                                                 char[][] pattern, int qos, int options, IntPtr properties);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_unsubscribe(IntPtr mosq, ref int mid, char[] pattern);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_unsubscribe_v5(IntPtr mosq, ref int mid, char[] pattern, IntPtr properties);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_unsubscribe_multiple(IntPtr mosq, ref int mid, int sub_count, char[][] pattern, IntPtr properties);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_message_copy(ref mosquitto_message dst, mosquitto_message src);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern void mosquitto_message_free(ref mosquitto_message message);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern void mosquitto_message_free_contents(ref mosquitto_message message);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_loop_forever(IntPtr mosq, int timeout, int max_packets);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_loop_start(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_loop_stop(IntPtr mosq, bool force);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_loop(IntPtr mosq, int timeout, int max_packets);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_loop_read(IntPtr mosq, int max_packets);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_loop_write(IntPtr mosq, int max_packets);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_loop_misc(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern int mosquitto_socket(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern bool mosquitto_want_write(IntPtr mosq);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_threaded_set(IntPtr mosq, bool threaded);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_int_option(IntPtr mosq, mosq_opt_t option, int value);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_string_option(IntPtr mosq, mosq_opt_t option, char[] value);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_void_option(IntPtr mosq, mosq_opt_t option, IntPtr value);
    
    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_reconnect_delay_set(IntPtr mosq, UInt32 reconnect_delay, 
                                                                  UInt32 reconnect_delay_max, bool reconnect_exponential_backoff);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern mosq_err_t mosquitto_max_inflight_messages_set(IntPtr mosq, UInt32 max_inflight_messages);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern void mosquitto_message_retry_set(IntPtr mosq, UInt32 message_retry);
    
    [DllImport(${LIB_MOSQUITTO})]
    public static extern void mosquitto_user_data_set(IntPtr mosq, IntPtr obj);

    [DllImport(${LIB_MOSQUITTO})]
    public static extern IntPtr mosquitto_user_data(IntPtr mosq);

    
} 