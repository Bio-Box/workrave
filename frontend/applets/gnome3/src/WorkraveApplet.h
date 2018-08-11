// WorkraveApplet.h
//
// Copyright (C) 2003 - 2011 Rob Caelers <robc@krandor.nl>
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//


#ifndef __WORKRAVEAPPLET_H__
#define __WORKRAVEAPPLET_H__

#include <panel-applet.h>

G_BEGIN_DECLS

#define WORKRAVE_TYPE_APPLET             (workrave_applet_get_type ())
#define WORKRAVE_APPLET(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), WORKRAVE_TYPE_APPLET, WorkraveApplet))
#define WORKRAVE_APPLET_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), WORKRAVE_TYPE_APPLET, WorkraveAppletClass))
#define WORKRAVE_IS_APPLET(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), WORKRAVE_TYPE_APPLET))
#define WORKRAVE_IS_APPLET_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), WORKRAVE_TYPE_APPLET))
#define WORKRAVE_APPLET_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj), WORKRAVE_TYPE_APPLET, WorkraveAppletClass))

typedef struct _WorkraveApplet        WorkraveApplet;
typedef struct _WorkraveAppletClass   WorkraveAppletClass;
typedef struct _WorkraveAppletPrivate WorkraveAppletPrivate;

struct _WorkraveApplet
{
  PanelApplet parent_object;

#ifdef HAVE_PANELAPPLET4
  /*< private >*/
  WorkraveAppletPrivate *priv;
#endif
};

struct _WorkraveAppletClass
{
  PanelAppletClass parent_class;
};


#define DBUS_SERVICE_APPLET "org.workrave.Workrave.GnomeApplet"
#define WORKRAVE_DBUS_ERROR g_quark_from_static_string ("workrave")

GType workrave_applet_get_type(void) G_GNUC_CONST;

gboolean workrave_applet_get_socket_id(WorkraveApplet *, guint *, GError **);
gboolean workrave_applet_get_size(WorkraveApplet *, guint *, GError **);
gboolean workrave_applet_get_orientation(WorkraveApplet *, guint *, GError **);
gboolean workrave_applet_set_menu_status(WorkraveApplet *, const char *, gboolean, GError **);
gboolean workrave_applet_get_menu_status(WorkraveApplet *, const char *, gboolean *, GError **);
gboolean workrave_applet_set_menu_active(WorkraveApplet *, const char *, gboolean, GError **);
gboolean workrave_applet_get_menu_active(WorkraveApplet *, const char *, gboolean *, GError **);

G_END_DECLS

#endif /*__WORKRAVEAPPLET_H__*/