#include <iostream>
#include <glib.h>
#include <unistd.h>
#include "libsigrok.h"
#include "proto.h"
#include "libsigrok-internal.h"

#define LOG_PREFIX "main"

extern SR_PRIV struct sr_dev_driver saleae_logic16_driver_info;

struct sr_context *sr_ctx = NULL;

using namespace std;
int main()
{
	struct sr_dev_inst *sdi;
    struct sr_dev_driver *driver;
    struct sr_session *session;
    GSList *devices, *l;
	GMainLoop *main_loop;

    cout << "trace_fast!" << endl;
    
    driver = &saleae_logic16_driver_info;

    if (sr_init(&sr_ctx) != SR_OK) {
        g_critical("Failed to initialize context.");
        return 0;
    }
    if(sr_session_new(sr_ctx, &session) != SR_OK){
        g_critical("Failed to initialize session.");
        return 0;
    }

    if (sr_driver_init(sr_ctx, driver) != SR_OK) {
        g_critical("Failed to initialize driver.");
        return 0;
    }

    devices = sr_driver_scan(driver, NULL);

	for (l = devices; l; l = l->next) {
		sdi = (struct sr_dev_inst *)l->data;

        if(sr_session_dev_add(session, sdi) != SR_OK) {
            g_critical("Failed to add device to session.");
            return 0;
        }

        if(sr_dev_open(sdi) != SR_OK){
            g_critical("Failed to open device");
            return 0;
        }
    }

	main_loop = g_main_loop_new(NULL, FALSE);

    if(sr_session_start(session) != SR_OK){
        g_critical("Failed to start session.");
        return 0;
    }

	g_main_loop_run(main_loop);

    while(1){
        sleep(1);
        cout << "." << endl;
        fflush(stdout); 
    }
    return 0;
}
