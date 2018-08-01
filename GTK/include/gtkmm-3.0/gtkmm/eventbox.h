// Generated by gmmproc 2.50.0 -- DO NOT MODIFY!
#ifndef _GTKMM_EVENTBOX_H
#define _GTKMM_EVENTBOX_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtkmm/bin.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventBox = struct _GtkEventBox;
using GtkEventBoxClass = struct _GtkEventBoxClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class EventBox_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Event capturing box.
 *
 * This widget adds an X Window where one does not
 * normally appear, allowing you to capture events.
 * It will receive any event which is specified
 * with set_events().
 *
 * This widget is generally used to add Gtk::Tooltip, button presses,
 * and clipping to widgets derived from Gtk::Misc.
 *
 * @ingroup Widgets
 */

class EventBox : public Bin
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef EventBox CppObjectType;
  typedef EventBox_Class CppClassType;
  typedef GtkEventBox BaseObjectType;
  typedef GtkEventBoxClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  EventBox(EventBox&& src) noexcept;
  EventBox& operator=(EventBox&& src) noexcept;

  // noncopyable
  EventBox(const EventBox&) = delete;
  EventBox& operator=(const EventBox&) = delete;

  ~EventBox() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class EventBox_Class;
  static CppClassType eventbox_class_;

protected:
  explicit EventBox(const Glib::ConstructParams& construct_params);
  explicit EventBox(GtkEventBox* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkEventBox*       gobj()       { return reinterpret_cast<GtkEventBox*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkEventBox* gobj() const { return reinterpret_cast<GtkEventBox*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

public:
  EventBox();

  
  /** Returns whether the event box has a visible window.
   * See set_visible_window() for details.
   * 
   * @newin{2,4}
   * 
   * @return <tt>true</tt> if the event box window is visible.
   */
  bool get_visible_window() const;
  
  /** Set whether the event box uses a visible or invisible child
   * window. The default is to use visible windows.
   * 
   * In an invisible window event box, the window that the
   * event box creates is a Gdk::INPUT_ONLY window, which
   * means that it is invisible and only serves to receive
   * events.
   * 
   * A visible window event box creates a visible (Gdk::INPUT_OUTPUT)
   * window that acts as the parent window for all the widgets
   * contained in the event box.
   * 
   * You should generally make your event box invisible if
   * you just want to trap events. Creating a visible window
   * may cause artifacts that are visible to the user, especially
   * if the user is using a theme with gradients or pixmaps.
   * 
   * The main reason to create a non input-only event box is if
   * you want to set the background to a different color or
   * draw on it.
   * 
   * There is one unexpected issue for an invisible event box that has its
   * window below the child. (See set_above_child().)
   * Since the input-only window is not an ancestor window of any windows
   * that descendent widgets of the event box create, events on these
   * windows aren’t propagated up by the windowing system, but only by GTK+.
   * The practical effect of this is if an event isn’t in the event
   * mask for the descendant window (see Gtk::Widget::add_events()),
   * it won’t be received by the event box.
   * 
   * This problem doesn’t occur for visible event boxes, because in
   * that case, the event box window is actually the ancestor of the
   * descendant windows, not just at the same place on the screen.
   * 
   * @newin{2,4}
   * 
   * @param visible_window <tt>true</tt> to make the event box have a visible window.
   */
  void set_visible_window(bool visible_window =  true);
  
  /** Returns whether the event box window is above or below the
   * windows of its child. See set_above_child()
   * for details.
   * 
   * @newin{2,4}
   * 
   * @return <tt>true</tt> if the event box window is above the
   * window of its child.
   */
  bool get_above_child() const;
  
  /** Set whether the event box window is positioned above the windows
   * of its child, as opposed to below it. If the window is above, all
   * events inside the event box will go to the event box. If the window
   * is below, events in windows of child widgets will first got to that
   * widget, and then to its parents.
   * 
   * The default is to keep the window below the child.
   * 
   * @newin{2,4}
   * 
   * @param above_child <tt>true</tt> if the event box window is above its child.
   */
  void set_above_child(bool above_child =  true);

  /** Whether the event box is visible, as opposed to invisible and only used to trap events.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_visible_window() ;

/** Whether the event box is visible, as opposed to invisible and only used to trap events.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_visible_window() const;

  /** Whether the event-trapping window of the eventbox is above the window of the child widget as opposed to below it.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_above_child() ;

/** Whether the event-trapping window of the eventbox is above the window of the child widget as opposed to below it.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_above_child() const;


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::EventBox
   */
  Gtk::EventBox* wrap(GtkEventBox* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_EVENTBOX_H */

