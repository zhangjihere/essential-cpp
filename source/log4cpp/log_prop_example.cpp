//
// Created by zhangji on 9/18/17.
//

#include "log_prop_example.h"

#include <log4cpp/Category.hh>
#include "log4cpp/FileAppender.hh"
#include <log4cpp/PropertyConfigurator.hh>


int main(int argc, char *argv[]) {
    std::string initFileName = "log4cpp.properties";
    log4cpp::PropertyConfigurator::configure(initFileName);

    log4cpp::Category &root = log4cpp::Category::getRoot();

    log4cpp::Category &sub1 = log4cpp::Category::getInstance(std::string("sub1"));

    log4cpp::Category &sub2 = log4cpp::Category::getInstance(std::string("sub1.sub2"));

    //add
    log4cpp::Appender *fileAppd = new log4cpp::FileAppender("cp4cc_log", "cp4cc_server.log", true, 00666);
    sub2.setAppender(fileAppd);

    root.warn("Storm is coming");

    sub1.debug("Received storm warning");
    sub1.info("Closing all hatches");

    sub2.debug("Hiding solar panels");
    sub2.error("Solar panels are blocked");
    sub2.debug("Applying protective shield");
    sub2.warn("Unfolding protective shield");
    sub2.info("Solar panels are shielded");

    sub1.info("All hatches closed");

    root.info("Ready for storm.");

    log4cpp::Category::shutdown();

    return 0;
}