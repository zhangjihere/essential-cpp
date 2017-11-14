//
// Created by zhangji on 9/18/17.
//

#include "log_test.h"

using namespace std;

int main(int argc, char *argv[]) {
    initLogger();

    log4cpp::Priority::Value i1 = logger.getPriority();
    logger.emerg("-------Priority:%s-------",log4cpp::Priority::getPriorityName(i1).c_str());
    logger.fatal("fatal storm %s", "0");
    logger.alert("alert storm %s", "100");
    logger.crit("crit storm %s", "200");
    logger.error("error storm %s", "300");

    logger.warn("warn storm %s", "400");
    logger.notice("notice storm %s", "500");
    logger.info("info storm %s", "600");
    logger.debug("debug storm %s", "700");

    logger.setPriority(log4cpp::Priority::ALERT);
    log4cpp::Priority::Value i2 = logger.getPriority();
    logger.emerg("-------Priority:%s-------",log4cpp::Priority::getPriorityName(i2).c_str());
    logger.fatal("fatal storm %s", "0");
    logger.alert("alert storm %s", "100");
    logger.crit("crit storm %s", "200");
    logger.error("error storm %s", "300");

    logger.warn("warn storm %s", "400");
    logger.notice("notice storm %s", "500");
    logger.info("info storm %s", "600");
    logger.debug("debug storm %s", "700");
    logger.shutdown();
}