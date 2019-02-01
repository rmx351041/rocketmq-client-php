#ifndef ROCKETMQ_CLIENT_PHP_PUSH_CONSUMER_H_
#define ROCKETMQ_CLIENT_PHP_PUSH_CONSUMER_H_

#include "common.h"
#include "message.h"
#include <rocketmq/DefaultMQPushConsumer.h>


class PushConsumer : public Php::Base{
    private:
        std::string groupName;
        std::string namesrv_domain;
        std::string topic;
        rocketmq::DefaultMQPushConsumer *consumer;
        Php::Value    callback;
        int msgListenerType;
        int maxRequestTime = 3600;

    public:
        PushConsumer(){}
        virtual ~PushConsumer(){}
        virtual void __construct(Php::Parameters &params);

        void doRebalance();

        void persistConsumerOffset();

        void persistConsumerOffsetByResetOffset();

        void setNamesrvDomain(Php::Parameters &param);

        Php::Value getNamesrvDomain();

        void setNamesrvAddr(Php::Parameters &param);

        Php::Value getNamesrvAddr(); 

        void setInstanceName(Php::Parameters &param);

        void setTryLockTimeout(Php::Parameters &param);

        void setConnectTimeout(Php::Parameters &param);

        void setListenerType(Php::Parameters &param);

        void setThreadCount(Php::Parameters &param);

        void subscribe(Php::Parameters &param);

        void setCallback(Php::Parameters &param);

        Php::Value getConsumeType();

        Php::Value getConsumeFromWhere();

        void setConsumeFromWhere(Php::Parameters &param);

        void setMaxRequestTime(Php::Parameters &param);

        void start();

        void shutdown();

        virtual void __destruct() { }

        void setSessionCredentials(Php::Parameters &param);
        Php::Value getSessionCredentials();

        Php::Value getMessageModel();
        void setMessageModel(Php::Parameters &params);

        // void setTcpTransportPullThreadNum(int num);
        void setTcpTransportPullThreadNum(Php::Parameters &param);

        // const int getTcpTransportPullThreadNum() const;
        Php::Value getTcpTransportPullThreadNum();

        // void setTcpTransportConnectTimeout(uint64_t timeout);  // ms
        void setTcpTransportConnectTimeout(Php::Parameters &param);
        // const uint64_t getTcpTransportConnectTimeout() const;
        Php::Value getTcpTransportConnectTimeout();

        // void setTcpTransportTryLockTimeout(uint64_t timeout);  // ms
        void setTcpTransportTryLockTimeout(Php::Parameters &param);
        // const uint64_t getTcpTransportConnectTimeout() const;
        Php::Value getTcpTransportTryLockTimeout();

        //void setUnitName(std::string unitName);
        void setUnitName(Php::Parameters &param);
        //const std::string& getUnitName();
        Php::Value getUnitName();


};

void registerPushConsumer(Php::Namespace &rocketMQNamespace);

#endif
