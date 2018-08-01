// Generated by gmmproc 2.50.0 -- DO NOT MODIFY!
#ifndef _GTKMM_CELLRENDERERTOGGLE_H
#define _GTKMM_CELLRENDERERTOGGLE_H


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

#include <gtkmm/cellrenderer.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererToggle = struct _GtkCellRendererToggle;
using GtkCellRendererToggleClass = struct _GtkCellRendererToggleClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class CellRendererToggle_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Renders a toggle button in a cell.
 * The button is drawn as a radio- or checkbutton, depending on the radio property. When activated, it
 * emits the toggled signal.
 *
 * @ingroup TreeView
 */

class CellRendererToggle : public CellRenderer
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRendererToggle CppObjectType;
  typedef CellRendererToggle_Class CppClassType;
  typedef GtkCellRendererToggle BaseObjectType;
  typedef GtkCellRendererToggleClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellRendererToggle(CellRendererToggle&& src) noexcept;
  CellRendererToggle& operator=(CellRendererToggle&& src) noexcept;

  // noncopyable
  CellRendererToggle(const CellRendererToggle&) = delete;
  CellRendererToggle& operator=(const CellRendererToggle&) = delete;

  ~CellRendererToggle() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class CellRendererToggle_Class;
  static CppClassType cellrenderertoggle_class_;

protected:
  explicit CellRendererToggle(const Glib::ConstructParams& construct_params);
  explicit CellRendererToggle(GtkCellRendererToggle* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkCellRendererToggle*       gobj()       { return reinterpret_cast<GtkCellRendererToggle*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkCellRendererToggle* gobj() const { return reinterpret_cast<GtkCellRendererToggle*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_toggled().
  virtual void on_toggled(const Glib::ustring& path);


private:

public:

  CellRendererToggle();


  /** Returns whether we’re rendering radio toggles rather than checkboxes.
   * 
   * @return <tt>true</tt> if we’re rendering radio toggles rather than checkboxes.
   */
  bool get_radio() const;
  
  /** If @a radio is <tt>true</tt>, the cell renderer renders a radio toggle
   * (i.e.\ a toggle in a group of mutually-exclusive toggles).
   * If <tt>false</tt>, it renders a check toggle (a standalone boolean option).
   * This can be set globally for the cell renderer, or changed just
   * before rendering each cell in the model (for Gtk::TreeView, you set
   * up a per-row setting using Gtk::TreeViewColumn to associate model
   * columns with cell renderer properties).
   * 
   * @param radio <tt>true</tt> to make the toggle look like a radio button.
   */
  void set_radio(bool radio =  true);
  
  /** Returns whether the cell renderer is active. See
   * set_active().
   * 
   * @return <tt>true</tt> if the cell renderer is active.
   */
  bool get_active() const;
  
  /** Activates or deactivates a cell renderer.
   * 
   * @param setting The value to set.
   */
  void set_active(bool setting =  true);
  
  /** Returns whether the cell renderer is activatable. See
   * set_activatable().
   * 
   * @newin{2,18}
   * 
   * @return <tt>true</tt> if the cell renderer is activatable.
   */
  bool get_activatable() const;
  
  /** Makes the cell renderer activatable.
   * 
   * @newin{2,18}
   * 
   * @param setting The value to set.
   */
  void set_activatable(bool setting =  true);


   //TODO: Maybe the parameter should be a TreePath.
  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%toggled(const Glib::ustring& path)</tt>
   *
   * The signal_toggled() signal is emitted when the cell is toggled. 
   * 
   * It is the responsibility of the application to update the model
   * with the correct value to store at @a path.  Often this is simply the
   * opposite of the value currently stored at @a path.
   * 
   * @param path String representation of Gtk::TreePath describing the 
   * event location.
   */

  Glib::SignalProxy< void,const Glib::ustring& > signal_toggled();


  /** The toggle button can be activated.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_activatable() ;

/** The toggle button can be activated.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_activatable() const;

  /** The toggle state of the button.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_active() ;

/** The toggle state of the button.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_active() const;

  /** The inconsistent state of the button.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_inconsistent() ;

/** The inconsistent state of the button.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_inconsistent() const;

  /** Draw the toggle button as a radio button.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_radio() ;

/** Draw the toggle button as a radio button.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_radio() const;

  
#ifndef GTKMM_DISABLE_DEPRECATED

/** Size of check or radio indicator.
   * @deprecated Use the min-width/min-height CSS properties of the check/radio node instead.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_indicator_size() ;

/** Size of check or radio indicator.
   * @deprecated Use the min-width/min-height CSS properties of the check/radio node instead.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_indicator_size() const;

#endif // GTKMM_DISABLE_DEPRECATED


  Glib::PropertyProxy_Base _property_renderable() override;


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
   * @relates Gtk::CellRendererToggle
   */
  Gtk::CellRendererToggle* wrap(GtkCellRendererToggle* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_CELLRENDERERTOGGLE_H */

