#ifndef WLR_SESSION_H
#define WLR_SESSION_H

#include <wayland-server.h>
#include <sys/types.h>

struct session_interface;

// Passed to the listeners of device_paused/resumed
struct device_arg {
	dev_t dev;
	int fd; // Only for device_resumed
};

struct wlr_session {
	const struct session_interface *iface;

	struct wl_signal device_paused;
	struct wl_signal device_resumed;
};

struct wlr_session *wlr_session_start(struct wl_display *disp);
void wlr_session_finish(struct wlr_session *session);
int wlr_session_open_file(struct wlr_session *restrict session,
	const char *restrict path);
void wlr_session_close_file(struct wlr_session *session, int fd);
bool wlr_session_change_vt(struct wlr_session *session, int vt);

#endif
