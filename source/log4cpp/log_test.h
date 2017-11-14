//
// Created by zhangji on 9/18/17.
//

#ifndef ESSENTIAL_CPP_LOG_TEST_H
#define ESSENTIAL_CPP_LOG_TEST_H

#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PropertyConfigurator.hh>

log4cpp::Category &logger = log4cpp::Category::getInstance(std::string("cp4cc_server_logger"));

/**
 * 初始化日志工具
 */
void initLogger() {
    log4cpp::PropertyConfigurator::configure("cp4cc_log.properties");
}

#endif //ESSENTIAL_CPP_LOG_TEST_H
