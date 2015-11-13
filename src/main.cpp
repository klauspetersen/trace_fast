#include <iostream>
#include <glib.h>
#include "libsigrok.h"
#include "proto.h"

extern SR_PRIV struct sr_dev_driver saleae_logic16_driver_info;


using namespace std;
int main()
{
    struct sr_dev_driver *driver;
    GSList *devices;

    cout << "trace_fast!" << endl;
    devices = sr_driver_scan(driver, NULL);
    return 0;
}
