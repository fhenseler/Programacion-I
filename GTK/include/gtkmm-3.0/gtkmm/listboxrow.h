// Generated by gmmproc 2.50.0 -- DO NOT MODIFY!
#ifndef _GTKMM_LISTBOXROW_H
#define _GTKMM_LISTBOXROW_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2013 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtkmm/bin.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListBoxRow = struct _GtkListBoxRow;
using GtkListBoxRowClass = struct _GtkListBoxRowClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class ListBoxRow_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** See the description of ListBox.
 *
 * @ingroup Widgets
 * @ingroup Containers
 *
 * @newin{3,10}
 */

class ListBoxRow : public Bin
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ListBoxRow CppObjectType;
  typedef ListBoxRow_Class CppClassType;
  typedef GtkListBoxRow BaseObjectType;
  typedef GtkListBoxRowClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ListBoxRow(ListBoxRow&& src) noexcept;
  ListBoxRow& operator=(ListBoxRow&& src) noexcept;

  // noncopyable
  ListBoxRow(const ListBoxRow&) = delete;
  ListBoxRow& operator=(const ListBoxRow&) = delete;

  ~ListBoxRow() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class ListBoxRow_Class;
  static CppClassType listboxrow_class_;

protected:
  explicit ListBoxRow(const Glib::ConstructParams& construct_params);
  explicit ListBoxRow(GtkListBoxRow* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkListBoxRow*       gobj()       { return reinterpret_cast<GtkListBoxRow*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkListBoxRow* gobj() const { return reinterpret_cast<GtkListBoxRow*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

public:
  ListBoxRow();

  
  /** Sets the current header of the ListBoxRow. This is only allowed to be called
   * from a ListBox::SlotUpdateHeader. It will replace any existing
   * header in the row, and be shown in front of the row in the ListBox.
   *
   * @newin{3,10}
   *
   * @param header The header.
   */
  void set_header(Widget& header);

  /** Removes the current header, if any. This is only allowed to be called
   * from a ListBox::SlotUpdateHeader.
   *
   * @newin{3,10}
   */
  void unset_header();

  
  /** Returns the current header of the ListBoxRow. This can be used
   * in a ListBox::SlotUpdateHeader to see if there is a header
   * set already, and if so to update the state of it.
   *
   * @newin{3,10}
   *
   * @return The current header, or <tt>0</tt> if none.
   */
  Widget* get_header();

  
  /** Returns the current header of the ListBoxRow. This can be used
   * in a ListBox::SlotUpdateHeader to see if there is a header
   * set already, and if so to update the state of it.
   *
   * @newin{3,10}
   *
   * @return The current header, or <tt>0</tt> if none.
   */
  const Widget* get_header() const;

  
  /** Gets the current index of the @a row in its Gtk::ListBox container.
   * 
   * @newin{3,10}
   * 
   * @return The index of the @a row, or -1 if the @a row is not in a listbox.
   */
  int get_index() const;
  
  /** Marks @a row as changed, causing any state that depends on this
   * to be updated. This affects sorting, filtering and headers.
   * 
   * Note that calls to this method must be in sync with the data
   * used for the row functions. For instance, if the list is
   * mirroring some external data set, and *two* rows changed in the
   * external data set then when you call changed()
   * on the first row the sort function must only read the new data
   * for the first of the two changed rows, otherwise the resorting
   * of the rows will be wrong.
   * 
   * This generally means that if you don’t fully control the data
   * model you have to duplicate the data that affects the listbox
   * row functions into the row widgets themselves. Another alternative
   * is to call invalidate_sort() on any model change,
   * but that is more expensive.
   * 
   * @newin{3,10}
   */
  void changed();

  
  /** Returns whether the child is currently selected in its
   * Gtk::ListBox container.
   * 
   * @newin{3,14}
   * 
   * @return <tt>true</tt> if @a row is selected.
   */
  bool is_selected() const;

  
  /** Set the Gtk::ListBoxRow::property_selectable() property for this row.
   * 
   * @newin{3,14}
   * 
   * @param selectable <tt>true</tt> to mark the row as selectable.
   */
  void set_selectable(bool selectable =  true);
  
  /** Gets the value of the Gtk::ListBoxRow::property_selectable() property
   * for this row.
   * 
   * @newin{3,14}
   * 
   * @return <tt>true</tt> if the row is selectable.
   */
  bool get_selectable() const;

  
  /** Set the Gtk::ListBoxRow::property_activatable() property for this row.
   * 
   * @newin{3,14}
   * 
   * @param activatable <tt>true</tt> to mark the row as activatable.
   */
  void set_activatable(bool activatable =  true);
  
  /** Gets the value of the Gtk::ListBoxRow::property_activatable() property
   * for this row.
   * 
   * @newin{3,14}
   * 
   * @return <tt>true</tt> if the row is activatable.
   */
  bool get_activatable() const;

  /** The property determines whether this row can be selected.
   * 
   * @newin{3,14}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_selectable() ;

/** The property determines whether this row can be selected.
   * 
   * @newin{3,14}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_selectable() const;

  /** The property determines whether the Gtk::ListBox::signal_row_activated()
   * signal will be emitted for this row.
   * 
   * @newin{3,14}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_activatable() ;

/** The property determines whether the Gtk::ListBox::signal_row_activated()
   * signal will be emitted for this row.
   * 
   * @newin{3,14}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_activatable() const;


   // Action signal


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::ListBoxRow
   */
  Gtk::ListBoxRow* wrap(GtkListBoxRow* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_LISTBOXROW_H */

