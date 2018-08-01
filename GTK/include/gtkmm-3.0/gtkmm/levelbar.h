// Generated by gmmproc 2.50.0 -- DO NOT MODIFY!
#ifndef _GTKMM_LEVELBAR_H
#define _GTKMM_LEVELBAR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/**
 * Copyright (C) 2012 The gtkmm Development Team
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

#include <gtkmm/widget.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLevelBar = struct _GtkLevelBar;
using GtkLevelBarClass = struct _GtkLevelBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class LevelBar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/** 
 *  @var LevelBarMode LEVEL_BAR_MODE_CONTINUOUS
 * The bar has a continuous mode.
 * 
 *  @var LevelBarMode LEVEL_BAR_MODE_DISCRETE
 * The bar has a discrete mode.
 * 
 *  @enum LevelBarMode
 * 
 * Describes how Gtk::LevelBar contents should be rendered.
 * Note that this enumeration could be extended with additional modes
 * in the future.
 * 
 * @newin{3,6}
 *
 * @ingroup gtkmmEnums
 */
enum LevelBarMode
{
  LEVEL_BAR_MODE_CONTINUOUS,
  LEVEL_BAR_MODE_DISCRETE
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::LevelBarMode> : public Glib::Value_Enum<Gtk::LevelBarMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


//TODO: Derive/Implement from Gtk::Orientable (and remove our mention of that
//in the class documentation when we can break ABI.

/** A bar that can used as a level indicator
 *
 * Typical use cases are displaying the strength
 * of a password, or showing the charge level of a battery.
 *
 * Use set_value() to set the current value, and
 * add_offset_value() to set the value offsets at which
 * the bar will be considered in a different state. There will be two offsets
 * by default on the level bar: Gtk::LEVEL_BAR_OFFSET_LOW and
 * Gtk::LEVEL_BAR_OFFSET_HIGH, with values 0.25 and 0.75 respectively.
 *
 * The default interval of values is between zero and one, but it's possible to
 * modify the interval using set_min_value() and
 * set_max_value(). The value will be always drawn in proportion to
 * the admissible interval, i.e. a value of 15 with a specified interval between
 * 10 and 20 is equivalent to a value of 0.5 with an interval between 0 and 1.
 * When Gtk::LEVEL_BAR_MODE_DISCRETE is used, the bar level is rendered
 * as a finite and number of separated blocks instead of a single one. The number
 * of blocks that will be rendered is equal to the number of units specified by
 * the admissible interval.
 * For instance, to build a bar rendered with five blocks, it's sufficient to
 * set the minimum value to 0 and the maximum value to 5 after changing the indicator
 * mode to discrete.
 *
 * @ingroup Widgets
 * @newin{3,6}
 */

class LevelBar : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef LevelBar CppObjectType;
  typedef LevelBar_Class CppClassType;
  typedef GtkLevelBar BaseObjectType;
  typedef GtkLevelBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  LevelBar(LevelBar&& src) noexcept;
  LevelBar& operator=(LevelBar&& src) noexcept;

  // noncopyable
  LevelBar(const LevelBar&) = delete;
  LevelBar& operator=(const LevelBar&) = delete;

  ~LevelBar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class LevelBar_Class;
  static CppClassType levelbar_class_;

protected:
  explicit LevelBar(const Glib::ConstructParams& construct_params);
  explicit LevelBar(GtkLevelBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkLevelBar*       gobj()       { return reinterpret_cast<GtkLevelBar*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkLevelBar* gobj() const { return reinterpret_cast<GtkLevelBar*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_offset_changed().
  virtual void on_offset_changed(const Glib::ustring& name);


private:

public:

  LevelBar();
  

  //TODO: Remove this when we can break ABI to derive from Orientable.
  /** Sets the orientation of the widget.
   *
   * @newin{3,18}
   *
   * @param orientation The widget’s new orientation.
   */
  void set_orientation(Orientation orientation);

  
  /** Sets the value of the Gtk::LevelBar::property_mode() property.
   * 
   * @newin{3,6}
   * 
   * @param mode A Gtk::LevelBarMode.
   */
  void set_mode(LevelBarMode mode);
  
  /** Returns the value of the Gtk::LevelBar::property_mode() property.
   * 
   * @newin{3,6}
   * 
   * @return A Gtk::LevelBarMode.
   */
  LevelBarMode get_mode() const;

  
  /** Sets the value of the Gtk::LevelBar::property_value() property.
   * 
   * @newin{3,6}
   * 
   * @param value A value in the interval between
   * Gtk::LevelBar::property_min_value() and Gtk::LevelBar::property_max_value().
   */
  void set_value(double value);
  
  /** Returns the value of the Gtk::LevelBar::property_value() property.
   * 
   * @newin{3,6}
   * 
   * @return A value in the interval between
   * Gtk::LevelBar::property_min_value() and Gtk::LevelBar::property_max_value().
   */
  double get_value() const;

  
  /** Sets the value of the Gtk::LevelBar::property_min_value() property.
   * 
   * You probably want to update preexisting level offsets after calling
   * this function.
   * 
   * @newin{3,6}
   * 
   * @param value A positive value.
   */
  void set_min_value(double value);
  
  /** Returns the value of the Gtk::LevelBar::property_min_value() property.
   * 
   * @newin{3,6}
   * 
   * @return A positive value.
   */
  double get_min_value() const;

  
  /** Sets the value of the Gtk::LevelBar::property_max_value() property.
   * 
   * You probably want to update preexisting level offsets after calling
   * this function.
   * 
   * @newin{3,6}
   * 
   * @param value A positive value.
   */
  void set_max_value(double value);
  
  /** Returns the value of the Gtk::LevelBar::property_max_value() property.
   * 
   * @newin{3,6}
   * 
   * @return A positive value.
   */
  double get_max_value() const;

  
  /** Sets the value of the Gtk::LevelBar::property_inverted() property.
   * 
   * @newin{3,8}
   * 
   * @param inverted <tt>true</tt> to invert the level bar.
   */
  void set_inverted(bool inverted =  true);
  
  /** Return the value of the Gtk::LevelBar::property_inverted() property.
   * 
   * @newin{3,8}
   * 
   * @return <tt>true</tt> if the level bar is inverted.
   */
  bool get_inverted() const;


  /** Adds a new offset marker on @a self at the position specified by @a value.
   * When the bar value is in the interval topped by @a value (or between @a value
   * and Gtk::LevelBar::property_max_value() in case the offset is the last one on the bar)
   * a style class named `level-` @a name will be applied
   * when rendering the level bar fill.
   * If another offset marker named @a name exists, its value will be
   * replaced by @a value.
   * 
   * @newin{3,6}
   * 
   * @param name The name of the new offset.
   * @param value The value for the new offset.
   */
  void add_offset_value(const Glib::ustring& name, double value);
  
  /** Removes an offset marker previously added with
   * add_offset_value().
   * 
   * @newin{3,6}
   * 
   * @param name The name of an offset in the bar.
   */
  void remove_offset_value(const Glib::ustring& name);
  
  /** Fetches the value specified for the offset marker @a name in @a self,
   * returning <tt>true</tt> in case an offset named @a name was found.
   * 
   * @newin{3,6}
   * 
   * @param name The name of an offset in the bar.
   * @param value Location where to store the value.
   * @return <tt>true</tt> if the specified offset is found.
   */
  bool get_offset_value(const Glib::ustring& name, double& value) const;

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%offset_changed(const Glib::ustring& name)</tt>
   *
   * Emitted when an offset specified on the bar changes value as an
   * effect to Gtk::LevelBar::add_offset_value() being called.
   * 
   * The signal supports detailed connections; you can connect to the
   * detailed signal "changed::x" in order to only receive callbacks when
   * the value of offset "x" changes.
   * 
   * @newin{3,6}
   * 
   * @param name The name of the offset that changed value.
   */

  Glib::SignalProxy< void,const Glib::ustring& > signal_offset_changed();


  /** The Gtk::LevelBar::property_value() property determines the currently
   * filled value of the level bar.
   * 
   * @newin{3,6}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_value() ;

/** The Gtk::LevelBar::property_value() property determines the currently
   * filled value of the level bar.
   * 
   * @newin{3,6}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_value() const;

  /** The Gtk::LevelBar::property_min_value() property determines the minimum value of
   * the interval that can be displayed by the bar.
   * 
   * @newin{3,6}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_min_value() ;

/** The Gtk::LevelBar::property_min_value() property determines the minimum value of
   * the interval that can be displayed by the bar.
   * 
   * @newin{3,6}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_min_value() const;

  /** The Gtk::LevelBar::property_max_value() property determaxes the maximum value of
   * the interval that can be displayed by the bar.
   * 
   * @newin{3,6}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_max_value() ;

/** The Gtk::LevelBar::property_max_value() property determaxes the maximum value of
   * the interval that can be displayed by the bar.
   * 
   * @newin{3,6}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_max_value() const;

  /** The Gtk::LevelBar::property_mode() property determines the way Gtk::LevelBar
   * interprets the value properties to draw the level fill area.
   * Specifically, when the value is Gtk::LEVEL_BAR_MODE_CONTINUOUS,
   * Gtk::LevelBar will draw a single block representing the current value in
   * that area; when the value is Gtk::LEVEL_BAR_MODE_DISCRETE,
   * the widget will draw a succession of separate blocks filling the
   * draw area, with the number of blocks being equal to the units separating
   * the integral roundings of Gtk::LevelBar::property_min_value() and Gtk::LevelBar::property_max_value().
   * 
   * @newin{3,6}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< LevelBarMode > property_mode() ;

/** The Gtk::LevelBar::property_mode() property determines the way Gtk::LevelBar
   * interprets the value properties to draw the level fill area.
   * Specifically, when the value is Gtk::LEVEL_BAR_MODE_CONTINUOUS,
   * Gtk::LevelBar will draw a single block representing the current value in
   * that area; when the value is Gtk::LEVEL_BAR_MODE_DISCRETE,
   * the widget will draw a succession of separate blocks filling the
   * draw area, with the number of blocks being equal to the units separating
   * the integral roundings of Gtk::LevelBar::property_min_value() and Gtk::LevelBar::property_max_value().
   * 
   * @newin{3,6}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< LevelBarMode > property_mode() const;

  /** Level bars normally grow from top to bottom or left to right.
   * Inverted level bars grow in the opposite direction.
   * 
   * @newin{3,8}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_inverted() ;

/** Level bars normally grow from top to bottom or left to right.
   * Inverted level bars grow in the opposite direction.
   * 
   * @newin{3,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_inverted() const;


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
   * @relates Gtk::LevelBar
   */
  Gtk::LevelBar* wrap(GtkLevelBar* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_LEVELBAR_H */

