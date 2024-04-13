#include <common/GeneratorInterface.h>

#include <alsa/asoundlib.h>
#include <alsa/version.h>

#include <type_traits>

template<auto>
struct fex_gen_config {
  unsigned version = 2;
};

// Function, parameter index, parameter type [optional]
template<auto, int, typename = void>
struct fex_gen_param {};

template<typename>
struct fex_gen_type {};

template<>
struct fex_gen_type<snd_pcm_status_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_shm_area> : fexgen::opaque_type {};

template<>
struct fex_gen_type<snd_async_handler_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<std::remove_pointer_t<snd_config_iterator_t>> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_config_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_config_update_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_ctl_card_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_ctl_elem_id_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_ctl_elem_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_ctl_elem_list_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_ctl_elem_value_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_ctl_event_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_ctl_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_devname_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_hctl_elem_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_hctl_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_hwdep_dsp_image_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_hwdep_dsp_status_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_hwdep_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_hwdep_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_input_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_midi_event_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_mixer_class_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_mixer_elem_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_mixer_selem_id_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_mixer_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_output_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_access_mask_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_format_mask_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_hook_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_hw_params_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_scope_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_subformat_mask_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_sw_params_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_pcm_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_rawmidi_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_rawmidi_params_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_rawmidi_status_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_rawmidi_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_sctl_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_client_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_client_pool_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_ev_ext_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_port_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_port_subscribe_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_query_subscribe_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_queue_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_queue_status_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_queue_tempo_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_queue_timer_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_remove_events_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_system_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_seq_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_ginfo_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_gparams_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_gstatus_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_id_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_info_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_params_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_query_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_status_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timer_t> : fexgen::opaque_type {};
template<>
struct fex_gen_type<snd_timestamp_t> : fexgen::opaque_type {};

template<>
struct fex_gen_type<FILE> : fexgen::opaque_type {};

// Union types with compatible data layout
template<>
struct fex_gen_type<snd_pcm_sync_id_t> : fexgen::assume_compatible_data_layout {};
template<>
struct fex_gen_type<snd_seq_timestamp> : fexgen::assume_compatible_data_layout {};
// Has anonymous union member
template<>
struct fex_gen_type<snd_seq_event> : fexgen::assume_compatible_data_layout {};

#ifndef IS_32BIT_THUNK
// TODO: Convert vtable
template<>
struct fex_gen_type<snd_pcm_scope_ops_t> : fexgen::assume_compatible_data_layout {};
#endif

template<>
struct fex_gen_config<snd_asoundlib_version> {};
#if SND_LIB_VERSION < ((1 << 16) | (2 << 8) | (6))
// Exists on 1.2.6
int snd_dlpath(char* path, size_t path_len, const char* name);
#endif
template<>
struct fex_gen_config<snd_dlpath> {};
template<>
struct fex_gen_config<snd_dlopen> {};
template<>
struct fex_gen_config<snd_dlsym> {};
template<>
struct fex_gen_config<snd_dlclose> {};
// template<> struct fex_gen_config<snd_async_add_handler> {};
// template<> struct fex_gen_config<snd_async_del_handler> {};
// template<> struct fex_gen_config<snd_async_handler_get_fd> {};
// template<> struct fex_gen_config<snd_async_handler_get_signo> {};
// template<> struct fex_gen_config<snd_async_handler_get_callback_private> {};
template<>
struct fex_gen_config<snd_shm_area_create> {};
template<>
struct fex_gen_config<snd_shm_area_share> {};
template<>
struct fex_gen_config<snd_shm_area_destroy> {};
template<>
struct fex_gen_config<snd_user_file> {};
template<>
struct fex_gen_config<snd_input_stdio_open> {};
template<>
struct fex_gen_config<snd_input_stdio_attach> {};
template<>
struct fex_gen_config<snd_input_buffer_open> {};
template<>
struct fex_gen_config<snd_input_close> {};
template<>
struct fex_gen_config<snd_input_gets> {};
template<>
struct fex_gen_config<snd_input_getc> {};
template<>
struct fex_gen_config<snd_input_ungetc> {};
template<>
struct fex_gen_config<snd_output_stdio_open> {};
template<>
struct fex_gen_config<snd_output_stdio_attach> {};
template<>
struct fex_gen_config<snd_output_buffer_open> {};
template<>
struct fex_gen_config<snd_output_buffer_string> {};
template<>
struct fex_gen_config<snd_output_close> {};
template<>
struct fex_gen_config<snd_output_puts> {};
template<>
struct fex_gen_config<snd_output_putc> {};
template<>
struct fex_gen_config<snd_output_flush> {};
template<>
struct fex_gen_config<snd_strerror> {};
// Variadic callback not supported
template<>
struct fex_gen_config<snd_lib_error_set_handler> : fexgen::callback_stub {};
// template<> struct fex_gen_config<snd_lib_error_set_local> {};
template<>
struct fex_gen_config<snd_config_topdir> {};
template<>
struct fex_gen_config<snd_config_top> {};
template<>
struct fex_gen_config<snd_config_load> {};
template<>
struct fex_gen_config<snd_config_load_override> {};
template<>
struct fex_gen_config<snd_config_save> {};
template<>
struct fex_gen_config<snd_config_update> {};
template<>
struct fex_gen_config<snd_config_update_r> {};
template<>
struct fex_gen_config<snd_config_update_free> {};
template<>
struct fex_gen_config<snd_config_update_free_global> {};
template<>
struct fex_gen_config<snd_config_update_ref> {};
template<>
struct fex_gen_config<snd_config_ref> {};
template<>
struct fex_gen_config<snd_config_unref> {};
template<>
struct fex_gen_config<snd_config_search> {};
template<>
struct fex_gen_config<snd_config_search_definition> {};
template<>
struct fex_gen_config<snd_config_expand> {};
template<>
struct fex_gen_config<snd_config_evaluate> {};
template<>
struct fex_gen_config<snd_config_add> {};
template<>
struct fex_gen_config<snd_config_add_before> {};
template<>
struct fex_gen_config<snd_config_add_after> {};
template<>
struct fex_gen_config<snd_config_remove> {};
template<>
struct fex_gen_config<snd_config_delete> {};
template<>
struct fex_gen_config<snd_config_delete_compound_members> {};
template<>
struct fex_gen_config<snd_config_copy> {};
template<>
struct fex_gen_config<snd_config_make> {};
template<>
struct fex_gen_config<snd_config_make_integer> {};
template<>
struct fex_gen_config<snd_config_make_integer64> {};
template<>
struct fex_gen_config<snd_config_make_real> {};
template<>
struct fex_gen_config<snd_config_make_string> {};
template<>
struct fex_gen_config<snd_config_make_pointer> {};
template<>
struct fex_gen_config<snd_config_make_compound> {};
// template<> struct fex_gen_config<snd_config_imake_integer> {};
// template<> struct fex_gen_config<snd_config_imake_integer64> {};
// template<> struct fex_gen_config<snd_config_imake_real> {};
template<>
struct fex_gen_config<snd_config_imake_string> {};
template<>
struct fex_gen_config<snd_config_imake_safe_string> {};
template<>
struct fex_gen_config<snd_config_imake_pointer> {};
template<>
struct fex_gen_config<snd_config_get_type> {};
template<>
struct fex_gen_config<snd_config_is_array> {};
template<>
struct fex_gen_config<snd_config_set_id> {};
template<>
struct fex_gen_config<snd_config_set_integer> {};
template<>
struct fex_gen_config<snd_config_set_integer64> {};
template<>
struct fex_gen_config<snd_config_set_real> {};
template<>
struct fex_gen_config<snd_config_set_string> {};
template<>
struct fex_gen_config<snd_config_set_ascii> {};
template<>
struct fex_gen_config<snd_config_set_pointer> {};
template<>
struct fex_gen_config<snd_config_get_id> {};
template<>
struct fex_gen_config<snd_config_get_integer> {};
template<>
struct fex_gen_config<snd_config_get_integer64> {};
template<>
struct fex_gen_config<snd_config_get_real> {};
template<>
struct fex_gen_config<snd_config_get_ireal> {};
template<>
struct fex_gen_config<snd_config_get_string> {};
template<>
struct fex_gen_config<snd_config_get_ascii> {};
template<>
struct fex_gen_config<snd_config_get_pointer> {};
template<>
struct fex_gen_config<snd_config_test_id> {};
template<>
struct fex_gen_config<snd_config_iterator_first> {};
// template<> struct fex_gen_config<snd_config_iterator_next> {};
template<>
struct fex_gen_config<snd_config_iterator_end> {};
// template<> struct fex_gen_config<snd_config_iterator_entry> {};
template<>
struct fex_gen_config<snd_config_get_bool_ascii> {};
template<>
struct fex_gen_config<snd_config_get_bool> {};
template<>
struct fex_gen_config<snd_config_get_ctl_iface_ascii> {};
template<>
struct fex_gen_config<snd_config_get_ctl_iface> {};
template<>
struct fex_gen_config<snd_names_list> {};
template<>
struct fex_gen_config<snd_names_list_free> {};
template<>
struct fex_gen_config<snd_pcm_open> {};
template<>
struct fex_gen_config<snd_pcm_open_lconf> {};
template<>
struct fex_gen_config<snd_pcm_open_fallback> {};
template<>
struct fex_gen_config<snd_pcm_close> {};
template<>
struct fex_gen_config<snd_pcm_name> {};
template<>
struct fex_gen_config<snd_pcm_type> {};
template<>
struct fex_gen_config<snd_pcm_stream> {};
template<>
struct fex_gen_config<snd_pcm_poll_descriptors_count> {};
template<>
struct fex_gen_config<snd_pcm_poll_descriptors> {};
template<>
struct fex_gen_config<snd_pcm_poll_descriptors_revents> {};
template<>
struct fex_gen_config<snd_pcm_nonblock> {};
// template<> struct fex_gen_config<snd_async_add_pcm_handler> {};
template<>
struct fex_gen_config<snd_async_handler_get_pcm> {};
template<>
struct fex_gen_config<snd_pcm_info> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_current> {};
template<>
struct fex_gen_config<snd_pcm_hw_params> {};
template<>
struct fex_gen_config<snd_pcm_hw_free> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_current> {};
template<>
struct fex_gen_config<snd_pcm_sw_params> {};
template<>
struct fex_gen_config<snd_pcm_prepare> {};
template<>
struct fex_gen_config<snd_pcm_reset> {};
template<>
struct fex_gen_config<snd_pcm_status> {};
template<>
struct fex_gen_config<snd_pcm_start> {};
template<>
struct fex_gen_config<snd_pcm_drop> {};
template<>
struct fex_gen_config<snd_pcm_drain> {};
template<>
struct fex_gen_config<snd_pcm_pause> {};
template<>
struct fex_gen_config<snd_pcm_state> {};
template<>
struct fex_gen_config<snd_pcm_hwsync> {};
template<>
struct fex_gen_config<snd_pcm_delay> {};
template<>
struct fex_gen_config<snd_pcm_resume> {};
template<>
struct fex_gen_config<snd_pcm_htimestamp> {};
template<>
struct fex_gen_config<snd_pcm_avail> {};
template<>
struct fex_gen_config<snd_pcm_avail_update> {};
template<>
struct fex_gen_config<snd_pcm_avail_delay> {};
template<>
struct fex_gen_config<snd_pcm_rewindable> {};
template<>
struct fex_gen_config<snd_pcm_rewind> {};
template<>
struct fex_gen_config<snd_pcm_forwardable> {};
template<>
struct fex_gen_config<snd_pcm_forward> {};
template<>
struct fex_gen_config<snd_pcm_writei> {};
template<>
struct fex_gen_config<snd_pcm_readi> {};
template<>
struct fex_gen_config<snd_pcm_writen> {};
template<>
struct fex_gen_config<snd_pcm_readn> {};
template<>
struct fex_gen_config<snd_pcm_wait> {};
template<>
struct fex_gen_config<snd_pcm_link> {};
template<>
struct fex_gen_config<snd_pcm_unlink> {};
template<>
struct fex_gen_config<snd_pcm_query_chmaps> {};
template<>
struct fex_gen_config<snd_pcm_query_chmaps_from_hw> {};
template<>
struct fex_gen_config<snd_pcm_free_chmaps> {};
template<>
struct fex_gen_config<snd_pcm_get_chmap> {};
template<>
struct fex_gen_config<snd_pcm_set_chmap> {};
template<>
struct fex_gen_config<snd_pcm_chmap_type_name> {};
template<>
struct fex_gen_config<snd_pcm_chmap_name> {};
template<>
struct fex_gen_config<snd_pcm_chmap_long_name> {};
template<>
struct fex_gen_config<snd_pcm_chmap_print> {};
template<>
struct fex_gen_config<snd_pcm_chmap_from_string> {};
template<>
struct fex_gen_config<snd_pcm_chmap_parse_string> {};
template<>
struct fex_gen_config<snd_pcm_recover> {};
template<>
struct fex_gen_config<snd_pcm_set_params> {};
template<>
struct fex_gen_config<snd_pcm_get_params> {};
template<>
struct fex_gen_config<snd_pcm_info_sizeof> {};
template<>
struct fex_gen_config<snd_pcm_info_malloc> {};
template<>
struct fex_gen_config<snd_pcm_info_free> {};
template<>
struct fex_gen_config<snd_pcm_info_copy> {};
template<>
struct fex_gen_config<snd_pcm_info_get_device> {};
template<>
struct fex_gen_config<snd_pcm_info_get_subdevice> {};
template<>
struct fex_gen_config<snd_pcm_info_get_stream> {};
template<>
struct fex_gen_config<snd_pcm_info_get_card> {};
template<>
struct fex_gen_config<snd_pcm_info_get_id> {};
template<>
struct fex_gen_config<snd_pcm_info_get_name> {};
template<>
struct fex_gen_config<snd_pcm_info_get_subdevice_name> {};
template<>
struct fex_gen_config<snd_pcm_info_get_class> {};
template<>
struct fex_gen_config<snd_pcm_info_get_subclass> {};
template<>
struct fex_gen_config<snd_pcm_info_get_subdevices_count> {};
template<>
struct fex_gen_config<snd_pcm_info_get_subdevices_avail> {};
template<>
struct fex_gen_config<snd_pcm_info_get_sync> {};
template<>
struct fex_gen_config<snd_pcm_info_set_device> {};
template<>
struct fex_gen_config<snd_pcm_info_set_subdevice> {};
template<>
struct fex_gen_config<snd_pcm_info_set_stream> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_any> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_can_mmap_sample_resolution> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_is_double> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_is_batch> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_is_block_transfer> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_is_monotonic> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_can_overrange> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_can_pause> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_can_resume> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_is_half_duplex> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_is_joint_duplex> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_can_sync_start> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_can_disable_period_wakeup> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_supports_audio_wallclock_ts> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_supports_audio_ts_type> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_rate_numden> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_sbits> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_fifo_size> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_sizeof> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_malloc> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_free> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_copy> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_access> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_access> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_access> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_access_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_access_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_access_mask> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_access_mask> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_format> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_format> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_format> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_format_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_format_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_format_mask> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_format_mask> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_subformat> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_subformat> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_subformat> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_subformat_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_subformat_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_subformat_mask> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_subformat_mask> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_channels> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_channels_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_channels_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_channels> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_channels> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_channels_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_channels_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_channels_minmax> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_channels_near> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_channels_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_channels_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_rate> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_rate_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_rate_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_rate> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_rate> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_rate_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_rate_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_rate_minmax> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_rate_near> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_rate_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_rate_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_rate_resample> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_rate_resample> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_export_buffer> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_export_buffer> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_wakeup> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_period_wakeup> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_period_time> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_period_time_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_period_time_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_period_time> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_time> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_time_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_time_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_time_minmax> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_time_near> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_time_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_time_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_period_size> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_period_size_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_period_size_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_period_size> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_size> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_size_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_size_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_size_minmax> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_size_near> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_size_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_size_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_period_size_integer> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_periods> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_periods_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_periods_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_periods> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_periods> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_periods_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_periods_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_periods_minmax> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_periods_near> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_periods_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_periods_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_periods_integer> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_buffer_time> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_buffer_time_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_buffer_time_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_buffer_time> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_time> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_time_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_time_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_time_minmax> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_time_near> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_time_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_time_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_buffer_size> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_buffer_size_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_buffer_size_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_test_buffer_size> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_size> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_size_min> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_size_max> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_size_minmax> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_size_near> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_size_first> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_set_buffer_size_last> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_get_min_align> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_sizeof> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_malloc> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_free> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_copy> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_boundary> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_set_tstamp_mode> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_tstamp_mode> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_set_tstamp_type> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_tstamp_type> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_set_avail_min> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_avail_min> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_set_period_event> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_period_event> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_set_start_threshold> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_start_threshold> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_set_stop_threshold> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_stop_threshold> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_set_silence_threshold> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_silence_threshold> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_set_silence_size> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_get_silence_size> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_sizeof> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_malloc> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_free> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_copy> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_none> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_any> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_test> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_empty> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_set> {};
template<>
struct fex_gen_config<snd_pcm_access_mask_reset> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_sizeof> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_malloc> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_free> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_copy> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_none> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_any> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_test> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_empty> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_set> {};
template<>
struct fex_gen_config<snd_pcm_format_mask_reset> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_sizeof> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_malloc> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_free> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_copy> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_none> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_any> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_test> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_empty> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_set> {};
template<>
struct fex_gen_config<snd_pcm_subformat_mask_reset> {};
template<>
struct fex_gen_config<snd_pcm_status_sizeof> {};
template<>
struct fex_gen_config<snd_pcm_status_malloc> {};
template<>
struct fex_gen_config<snd_pcm_status_free> {};
template<>
struct fex_gen_config<snd_pcm_status_copy> {};
template<>
struct fex_gen_config<snd_pcm_status_get_state> {};
template<>
struct fex_gen_config<snd_pcm_status_get_trigger_tstamp> {};
template<>
struct fex_gen_config<snd_pcm_status_get_trigger_htstamp> {};
template<>
struct fex_gen_config<snd_pcm_status_get_tstamp> {};
template<>
struct fex_gen_config<snd_pcm_status_get_htstamp> {};
template<>
struct fex_gen_config<snd_pcm_status_get_audio_htstamp> {};
template<>
struct fex_gen_config<snd_pcm_status_get_driver_htstamp> {};
template<>
struct fex_gen_config<snd_pcm_status_get_audio_htstamp_report> {};
template<>
struct fex_gen_config<snd_pcm_status_set_audio_htstamp_config> {};
template<>
struct fex_gen_config<snd_pcm_status_get_delay> {};
template<>
struct fex_gen_config<snd_pcm_status_get_avail> {};
template<>
struct fex_gen_config<snd_pcm_status_get_avail_max> {};
template<>
struct fex_gen_config<snd_pcm_status_get_overrange> {};
template<>
struct fex_gen_config<snd_pcm_type_name> {};
template<>
struct fex_gen_config<snd_pcm_stream_name> {};
template<>
struct fex_gen_config<snd_pcm_access_name> {};
template<>
struct fex_gen_config<snd_pcm_format_name> {};
template<>
struct fex_gen_config<snd_pcm_format_description> {};
template<>
struct fex_gen_config<snd_pcm_subformat_name> {};
template<>
struct fex_gen_config<snd_pcm_subformat_description> {};
template<>
struct fex_gen_config<snd_pcm_format_value> {};
// template<> struct fex_gen_config<snd_pcm_tstamp_mode_name> {};
// template<> struct fex_gen_config<snd_pcm_state_name> {};
template<>
struct fex_gen_config<snd_pcm_dump> {};
template<>
struct fex_gen_config<snd_pcm_dump_hw_setup> {};
template<>
struct fex_gen_config<snd_pcm_dump_sw_setup> {};
template<>
struct fex_gen_config<snd_pcm_dump_setup> {};
template<>
struct fex_gen_config<snd_pcm_hw_params_dump> {};
template<>
struct fex_gen_config<snd_pcm_sw_params_dump> {};
template<>
struct fex_gen_config<snd_pcm_status_dump> {};
template<>
struct fex_gen_config<snd_pcm_mmap_begin> {};
template<>
struct fex_gen_config<snd_pcm_mmap_commit> {};
template<>
struct fex_gen_config<snd_pcm_mmap_writei> {};
template<>
struct fex_gen_config<snd_pcm_mmap_readi> {};
template<>
struct fex_gen_config<snd_pcm_mmap_writen> {};
template<>
struct fex_gen_config<snd_pcm_mmap_readn> {};
template<>
struct fex_gen_config<snd_pcm_format_signed> {};
template<>
struct fex_gen_config<snd_pcm_format_unsigned> {};
template<>
struct fex_gen_config<snd_pcm_format_linear> {};
template<>
struct fex_gen_config<snd_pcm_format_float> {};
template<>
struct fex_gen_config<snd_pcm_format_little_endian> {};
template<>
struct fex_gen_config<snd_pcm_format_big_endian> {};
template<>
struct fex_gen_config<snd_pcm_format_cpu_endian> {};
template<>
struct fex_gen_config<snd_pcm_format_width> {};
template<>
struct fex_gen_config<snd_pcm_format_physical_width> {};
template<>
struct fex_gen_config<snd_pcm_build_linear_format> {};
template<>
struct fex_gen_config<snd_pcm_format_size> {};
template<>
struct fex_gen_config<snd_pcm_format_silence> {};
template<>
struct fex_gen_config<snd_pcm_format_silence_16> {};
template<>
struct fex_gen_config<snd_pcm_format_silence_32> {};
template<>
struct fex_gen_config<snd_pcm_format_silence_64> {};
template<>
struct fex_gen_config<snd_pcm_format_set_silence> {};
template<>
struct fex_gen_config<snd_pcm_bytes_to_frames> {};
template<>
struct fex_gen_config<snd_pcm_frames_to_bytes> {};
template<>
struct fex_gen_config<snd_pcm_bytes_to_samples> {};
template<>
struct fex_gen_config<snd_pcm_samples_to_bytes> {};
template<>
struct fex_gen_config<snd_pcm_area_silence> {};
template<>
struct fex_gen_config<snd_pcm_areas_silence> {};
template<>
struct fex_gen_config<snd_pcm_area_copy> {};
template<>
struct fex_gen_config<snd_pcm_areas_copy> {};
// template<> struct fex_gen_config<snd_pcm_areas_copy_wrap> {};
// template<> struct fex_gen_config<snd_pcm_hook_get_pcm> {};
// template<> struct fex_gen_config<snd_pcm_hook_get_private> {};
// template<> struct fex_gen_config<snd_pcm_hook_set_private> {};
// template<> struct fex_gen_config<snd_pcm_hook_add> {};
// template<> struct fex_gen_config<snd_pcm_hook_remove> {};
template<>
struct fex_gen_config<snd_pcm_meter_get_bufsize> {};
template<>
struct fex_gen_config<snd_pcm_meter_get_channels> {};
template<>
struct fex_gen_config<snd_pcm_meter_get_rate> {};
template<>
struct fex_gen_config<snd_pcm_meter_get_now> {};
template<>
struct fex_gen_config<snd_pcm_meter_get_boundary> {};
template<>
struct fex_gen_config<snd_pcm_meter_add_scope> {};
template<>
struct fex_gen_config<snd_pcm_meter_search_scope> {};
template<>
struct fex_gen_config<snd_pcm_scope_malloc> {};
template<>
struct fex_gen_config<snd_pcm_scope_set_ops> {};
template<>
struct fex_gen_config<snd_pcm_scope_set_name> {};
template<>
struct fex_gen_config<snd_pcm_scope_get_name> {};
template<>
struct fex_gen_config<snd_pcm_scope_get_callback_private> {};
template<>
struct fex_gen_config<snd_pcm_scope_set_callback_private> {};
template<>
struct fex_gen_config<snd_pcm_scope_s16_open> {};
template<>
struct fex_gen_config<snd_pcm_scope_s16_get_channel_buffer> {};
template<>
struct fex_gen_config<snd_spcm_init> {};
template<>
struct fex_gen_config<snd_spcm_init_duplex> {};
template<>
struct fex_gen_config<snd_spcm_init_get_params> {};
template<>
struct fex_gen_config<snd_rawmidi_open> {};
template<>
struct fex_gen_config<snd_rawmidi_open_lconf> {};
template<>
struct fex_gen_config<snd_rawmidi_close> {};
template<>
struct fex_gen_config<snd_rawmidi_poll_descriptors_count> {};
template<>
struct fex_gen_config<snd_rawmidi_poll_descriptors> {};
template<>
struct fex_gen_config<snd_rawmidi_poll_descriptors_revents> {};
template<>
struct fex_gen_config<snd_rawmidi_nonblock> {};
template<>
struct fex_gen_config<snd_rawmidi_info_sizeof> {};
template<>
struct fex_gen_config<snd_rawmidi_info_malloc> {};
template<>
struct fex_gen_config<snd_rawmidi_info_free> {};
template<>
struct fex_gen_config<snd_rawmidi_info_copy> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_device> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_subdevice> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_stream> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_card> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_flags> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_id> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_name> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_subdevice_name> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_subdevices_count> {};
template<>
struct fex_gen_config<snd_rawmidi_info_get_subdevices_avail> {};
template<>
struct fex_gen_config<snd_rawmidi_info_set_device> {};
template<>
struct fex_gen_config<snd_rawmidi_info_set_subdevice> {};
template<>
struct fex_gen_config<snd_rawmidi_info_set_stream> {};
template<>
struct fex_gen_config<snd_rawmidi_info> {};
template<>
struct fex_gen_config<snd_rawmidi_params_sizeof> {};
template<>
struct fex_gen_config<snd_rawmidi_params_malloc> {};
template<>
struct fex_gen_config<snd_rawmidi_params_free> {};
template<>
struct fex_gen_config<snd_rawmidi_params_copy> {};
template<>
struct fex_gen_config<snd_rawmidi_params_set_buffer_size> {};
template<>
struct fex_gen_config<snd_rawmidi_params_get_buffer_size> {};
template<>
struct fex_gen_config<snd_rawmidi_params_set_avail_min> {};
template<>
struct fex_gen_config<snd_rawmidi_params_get_avail_min> {};
template<>
struct fex_gen_config<snd_rawmidi_params_set_no_active_sensing> {};
template<>
struct fex_gen_config<snd_rawmidi_params_get_no_active_sensing> {};
template<>
struct fex_gen_config<snd_rawmidi_params> {};
template<>
struct fex_gen_config<snd_rawmidi_params_current> {};
template<>
struct fex_gen_config<snd_rawmidi_status_sizeof> {};
template<>
struct fex_gen_config<snd_rawmidi_status_malloc> {};
template<>
struct fex_gen_config<snd_rawmidi_status_free> {};
template<>
struct fex_gen_config<snd_rawmidi_status_copy> {};
template<>
struct fex_gen_config<snd_rawmidi_status_get_tstamp> {};
template<>
struct fex_gen_config<snd_rawmidi_status_get_avail> {};
template<>
struct fex_gen_config<snd_rawmidi_status_get_xruns> {};
template<>
struct fex_gen_config<snd_rawmidi_status> {};
template<>
struct fex_gen_config<snd_rawmidi_drain> {};
template<>
struct fex_gen_config<snd_rawmidi_drop> {};
template<>
struct fex_gen_config<snd_rawmidi_write> {};
template<>
struct fex_gen_config<snd_rawmidi_read> {};
template<>
struct fex_gen_config<snd_rawmidi_name> {};
template<>
struct fex_gen_config<snd_rawmidi_type> {};
template<>
struct fex_gen_config<snd_rawmidi_stream> {};
template<>
struct fex_gen_config<snd_timer_query_open> {};
template<>
struct fex_gen_config<snd_timer_query_open_lconf> {};
template<>
struct fex_gen_config<snd_timer_query_close> {};
template<>
struct fex_gen_config<snd_timer_query_next_device> {};
template<>
struct fex_gen_config<snd_timer_query_info> {};
template<>
struct fex_gen_config<snd_timer_query_params> {};
template<>
struct fex_gen_config<snd_timer_query_status> {};
template<>
struct fex_gen_config<snd_timer_open> {};
template<>
struct fex_gen_config<snd_timer_open_lconf> {};
template<>
struct fex_gen_config<snd_timer_close> {};
// template<> struct fex_gen_config<snd_async_add_timer_handler> {};
// template<> struct fex_gen_config<snd_async_handler_get_timer> {};
template<>
struct fex_gen_config<snd_timer_poll_descriptors_count> {};
template<>
struct fex_gen_config<snd_timer_poll_descriptors> {};
template<>
struct fex_gen_config<snd_timer_poll_descriptors_revents> {};
template<>
struct fex_gen_config<snd_timer_info> {};
template<>
struct fex_gen_config<snd_timer_params> {};
template<>
struct fex_gen_config<snd_timer_status> {};
template<>
struct fex_gen_config<snd_timer_start> {};
template<>
struct fex_gen_config<snd_timer_stop> {};
template<>
struct fex_gen_config<snd_timer_continue> {};
template<>
struct fex_gen_config<snd_timer_read> {};
template<>
struct fex_gen_config<snd_timer_id_sizeof> {};
template<>
struct fex_gen_config<snd_timer_id_malloc> {};
template<>
struct fex_gen_config<snd_timer_id_free> {};
template<>
struct fex_gen_config<snd_timer_id_copy> {};
template<>
struct fex_gen_config<snd_timer_id_set_class> {};
template<>
struct fex_gen_config<snd_timer_id_get_class> {};
template<>
struct fex_gen_config<snd_timer_id_set_sclass> {};
template<>
struct fex_gen_config<snd_timer_id_get_sclass> {};
template<>
struct fex_gen_config<snd_timer_id_set_card> {};
template<>
struct fex_gen_config<snd_timer_id_get_card> {};
template<>
struct fex_gen_config<snd_timer_id_set_device> {};
template<>
struct fex_gen_config<snd_timer_id_get_device> {};
template<>
struct fex_gen_config<snd_timer_id_set_subdevice> {};
template<>
struct fex_gen_config<snd_timer_id_get_subdevice> {};
template<>
struct fex_gen_config<snd_timer_ginfo_sizeof> {};
template<>
struct fex_gen_config<snd_timer_ginfo_malloc> {};
template<>
struct fex_gen_config<snd_timer_ginfo_free> {};
template<>
struct fex_gen_config<snd_timer_ginfo_copy> {};
template<>
struct fex_gen_config<snd_timer_ginfo_set_tid> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_tid> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_flags> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_card> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_id> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_name> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_resolution> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_resolution_min> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_resolution_max> {};
template<>
struct fex_gen_config<snd_timer_ginfo_get_clients> {};
template<>
struct fex_gen_config<snd_timer_info_sizeof> {};
template<>
struct fex_gen_config<snd_timer_info_malloc> {};
template<>
struct fex_gen_config<snd_timer_info_free> {};
template<>
struct fex_gen_config<snd_timer_info_copy> {};
template<>
struct fex_gen_config<snd_timer_info_is_slave> {};
template<>
struct fex_gen_config<snd_timer_info_get_card> {};
template<>
struct fex_gen_config<snd_timer_info_get_id> {};
template<>
struct fex_gen_config<snd_timer_info_get_name> {};
template<>
struct fex_gen_config<snd_timer_info_get_resolution> {};
template<>
struct fex_gen_config<snd_timer_params_sizeof> {};
template<>
struct fex_gen_config<snd_timer_params_malloc> {};
template<>
struct fex_gen_config<snd_timer_params_free> {};
template<>
struct fex_gen_config<snd_timer_params_copy> {};
template<>
struct fex_gen_config<snd_timer_params_set_auto_start> {};
template<>
struct fex_gen_config<snd_timer_params_get_auto_start> {};
template<>
struct fex_gen_config<snd_timer_params_set_exclusive> {};
template<>
struct fex_gen_config<snd_timer_params_get_exclusive> {};
template<>
struct fex_gen_config<snd_timer_params_set_early_event> {};
template<>
struct fex_gen_config<snd_timer_params_get_early_event> {};
template<>
struct fex_gen_config<snd_timer_params_set_ticks> {};
template<>
struct fex_gen_config<snd_timer_params_get_ticks> {};
template<>
struct fex_gen_config<snd_timer_params_set_queue_size> {};
template<>
struct fex_gen_config<snd_timer_params_get_queue_size> {};
template<>
struct fex_gen_config<snd_timer_params_set_filter> {};
template<>
struct fex_gen_config<snd_timer_params_get_filter> {};
template<>
struct fex_gen_config<snd_timer_status_sizeof> {};
template<>
struct fex_gen_config<snd_timer_status_malloc> {};
template<>
struct fex_gen_config<snd_timer_status_free> {};
template<>
struct fex_gen_config<snd_timer_status_copy> {};
template<>
struct fex_gen_config<snd_timer_status_get_timestamp> {};
template<>
struct fex_gen_config<snd_timer_status_get_resolution> {};
template<>
struct fex_gen_config<snd_timer_status_get_lost> {};
template<>
struct fex_gen_config<snd_timer_status_get_overrun> {};
template<>
struct fex_gen_config<snd_timer_status_get_queue> {};
template<>
struct fex_gen_config<snd_timer_info_get_ticks> {};
template<>
struct fex_gen_config<snd_hwdep_open> {};
template<>
struct fex_gen_config<snd_hwdep_close> {};
template<>
struct fex_gen_config<snd_hwdep_poll_descriptors> {};
template<>
struct fex_gen_config<snd_hwdep_poll_descriptors_count> {};
template<>
struct fex_gen_config<snd_hwdep_poll_descriptors_revents> {};
template<>
struct fex_gen_config<snd_hwdep_nonblock> {};
template<>
struct fex_gen_config<snd_hwdep_info> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_load> {};
template<>
struct fex_gen_config<snd_hwdep_ioctl> {};
template<>
struct fex_gen_config<snd_hwdep_write> {};
template<>
struct fex_gen_config<snd_hwdep_read> {};
template<>
struct fex_gen_config<snd_hwdep_info_sizeof> {};
template<>
struct fex_gen_config<snd_hwdep_info_malloc> {};
template<>
struct fex_gen_config<snd_hwdep_info_free> {};
template<>
struct fex_gen_config<snd_hwdep_info_copy> {};
template<>
struct fex_gen_config<snd_hwdep_info_get_device> {};
template<>
struct fex_gen_config<snd_hwdep_info_get_card> {};
template<>
struct fex_gen_config<snd_hwdep_info_get_id> {};
template<>
struct fex_gen_config<snd_hwdep_info_get_name> {};
template<>
struct fex_gen_config<snd_hwdep_info_get_iface> {};
template<>
struct fex_gen_config<snd_hwdep_info_set_device> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_sizeof> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_malloc> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_free> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_copy> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_get_version> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_get_id> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_get_num_dsps> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_get_dsp_loaded> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_status_get_chip_ready> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_sizeof> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_malloc> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_free> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_copy> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_get_index> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_get_name> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_get_image> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_get_length> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_set_index> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_set_name> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_set_image> {};
template<>
struct fex_gen_config<snd_hwdep_dsp_image_set_length> {};
template<>
struct fex_gen_config<snd_card_load> {};
template<>
struct fex_gen_config<snd_card_next> {};
template<>
struct fex_gen_config<snd_card_get_index> {};
template<>
struct fex_gen_config<snd_card_get_name> {};
template<>
struct fex_gen_config<snd_card_get_longname> {};
template<>
struct fex_gen_config<snd_device_name_hint> {};
template<>
struct fex_gen_config<snd_device_name_free_hint> {};
template<>
struct fex_gen_config<snd_device_name_get_hint> {};
template<>
struct fex_gen_config<snd_ctl_open> {};
template<>
struct fex_gen_config<snd_ctl_open_lconf> {};
template<>
struct fex_gen_config<snd_ctl_open_fallback> {};
template<>
struct fex_gen_config<snd_ctl_close> {};
template<>
struct fex_gen_config<snd_ctl_nonblock> {};
// template<> struct fex_gen_config<snd_async_add_ctl_handler> {};
// template<> struct fex_gen_config<snd_async_handler_get_ctl> {};
template<>
struct fex_gen_config<snd_ctl_poll_descriptors_count> {};
template<>
struct fex_gen_config<snd_ctl_poll_descriptors> {};
template<>
struct fex_gen_config<snd_ctl_poll_descriptors_revents> {};
template<>
struct fex_gen_config<snd_ctl_subscribe_events> {};
template<>
struct fex_gen_config<snd_ctl_card_info> {};
template<>
struct fex_gen_config<snd_ctl_elem_list> {};
template<>
struct fex_gen_config<snd_ctl_elem_info> {};
template<>
struct fex_gen_config<snd_ctl_elem_read> {};
template<>
struct fex_gen_config<snd_ctl_elem_write> {};
template<>
struct fex_gen_config<snd_ctl_elem_lock> {};
template<>
struct fex_gen_config<snd_ctl_elem_unlock> {};
template<>
struct fex_gen_config<snd_ctl_elem_tlv_read> {};
template<>
struct fex_gen_config<snd_ctl_elem_tlv_write> {};
template<>
struct fex_gen_config<snd_ctl_elem_tlv_command> {};
template<>
struct fex_gen_config<snd_ctl_hwdep_next_device> {};
template<>
struct fex_gen_config<snd_ctl_hwdep_info> {};
template<>
struct fex_gen_config<snd_ctl_pcm_next_device> {};
template<>
struct fex_gen_config<snd_ctl_pcm_info> {};
template<>
struct fex_gen_config<snd_ctl_pcm_prefer_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_rawmidi_next_device> {};
template<>
struct fex_gen_config<snd_ctl_rawmidi_info> {};
template<>
struct fex_gen_config<snd_ctl_rawmidi_prefer_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_set_power_state> {};
template<>
struct fex_gen_config<snd_ctl_get_power_state> {};
template<>
struct fex_gen_config<snd_ctl_read> {};
template<>
struct fex_gen_config<snd_ctl_wait> {};
template<>
struct fex_gen_config<snd_ctl_name> {};
template<>
struct fex_gen_config<snd_ctl_type> {};
template<>
struct fex_gen_config<snd_ctl_elem_type_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_iface_name> {};
template<>
struct fex_gen_config<snd_ctl_event_type_name> {};
template<>
struct fex_gen_config<snd_ctl_event_elem_get_mask> {};
template<>
struct fex_gen_config<snd_ctl_event_elem_get_numid> {};
template<>
struct fex_gen_config<snd_ctl_event_elem_get_id> {};
template<>
struct fex_gen_config<snd_ctl_event_elem_get_interface> {};
template<>
struct fex_gen_config<snd_ctl_event_elem_get_device> {};
template<>
struct fex_gen_config<snd_ctl_event_elem_get_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_event_elem_get_name> {};
template<>
struct fex_gen_config<snd_ctl_event_elem_get_index> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_alloc_space> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_free_space> {};
template<>
struct fex_gen_config<snd_ctl_ascii_elem_id_get> {};
template<>
struct fex_gen_config<snd_ctl_ascii_elem_id_parse> {};
template<>
struct fex_gen_config<snd_ctl_ascii_value_parse> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_sizeof> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_malloc> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_free> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_clear> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_copy> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_get_numid> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_get_interface> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_get_device> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_get_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_get_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_get_index> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_set_numid> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_set_interface> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_set_device> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_set_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_set_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_id_set_index> {};
template<>
struct fex_gen_config<snd_ctl_card_info_sizeof> {};
template<>
struct fex_gen_config<snd_ctl_card_info_malloc> {};
template<>
struct fex_gen_config<snd_ctl_card_info_free> {};
template<>
struct fex_gen_config<snd_ctl_card_info_clear> {};
template<>
struct fex_gen_config<snd_ctl_card_info_copy> {};
template<>
struct fex_gen_config<snd_ctl_card_info_get_card> {};
template<>
struct fex_gen_config<snd_ctl_card_info_get_id> {};
template<>
struct fex_gen_config<snd_ctl_card_info_get_driver> {};
template<>
struct fex_gen_config<snd_ctl_card_info_get_name> {};
template<>
struct fex_gen_config<snd_ctl_card_info_get_longname> {};
template<>
struct fex_gen_config<snd_ctl_card_info_get_mixername> {};
template<>
struct fex_gen_config<snd_ctl_card_info_get_components> {};
template<>
struct fex_gen_config<snd_ctl_event_sizeof> {};
template<>
struct fex_gen_config<snd_ctl_event_malloc> {};
template<>
struct fex_gen_config<snd_ctl_event_free> {};
template<>
struct fex_gen_config<snd_ctl_event_clear> {};
template<>
struct fex_gen_config<snd_ctl_event_copy> {};
template<>
struct fex_gen_config<snd_ctl_event_get_type> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_sizeof> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_malloc> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_free> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_clear> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_copy> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_set_offset> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_used> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_count> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_id> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_numid> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_interface> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_device> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_list_get_index> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_sizeof> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_malloc> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_free> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_clear> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_copy> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_type> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_readable> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_writable> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_volatile> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_inactive> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_locked> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_tlv_readable> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_tlv_writable> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_tlv_commandable> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_owner> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_is_user> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_owner> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_count> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_min> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_max> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_step> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_min64> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_max64> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_step64> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_items> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_set_item> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_item_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_dimensions> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_dimension> {};
// template<> struct fex_gen_config<snd_ctl_elem_info_set_dimension> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_id> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_numid> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_interface> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_device> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_get_index> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_set_id> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_set_numid> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_set_interface> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_set_device> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_set_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_set_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_info_set_index> {};
template<>
struct fex_gen_config<snd_ctl_add_integer_elem_set> {};
template<>
struct fex_gen_config<snd_ctl_add_integer64_elem_set> {};
template<>
struct fex_gen_config<snd_ctl_add_boolean_elem_set> {};
// template<> struct fex_gen_config<snd_ctl_add_enumerated_elem_set> {};
template<>
struct fex_gen_config<snd_ctl_add_bytes_elem_set> {};
template<>
struct fex_gen_config<snd_ctl_elem_add_integer> {};
template<>
struct fex_gen_config<snd_ctl_elem_add_integer64> {};
template<>
struct fex_gen_config<snd_ctl_elem_add_boolean> {};
// template<> struct fex_gen_config<snd_ctl_elem_add_enumerated> {};
template<>
struct fex_gen_config<snd_ctl_elem_add_iec958> {};
template<>
struct fex_gen_config<snd_ctl_elem_remove> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_sizeof> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_malloc> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_free> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_clear> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_copy> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_compare> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_id> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_numid> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_interface> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_device> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_index> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_id> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_numid> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_interface> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_device> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_subdevice> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_name> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_index> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_boolean> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_integer> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_integer64> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_enumerated> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_byte> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_boolean> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_integer> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_integer64> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_enumerated> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_byte> {};
template<>
struct fex_gen_config<snd_ctl_elem_set_bytes> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_bytes> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_get_iec958> {};
template<>
struct fex_gen_config<snd_ctl_elem_value_set_iec958> {};
template<>
struct fex_gen_config<snd_tlv_parse_dB_info> {};
template<>
struct fex_gen_config<snd_tlv_get_dB_range> {};
template<>
struct fex_gen_config<snd_tlv_convert_to_dB> {};
template<>
struct fex_gen_config<snd_tlv_convert_from_dB> {};
template<>
struct fex_gen_config<snd_ctl_get_dB_range> {};
template<>
struct fex_gen_config<snd_ctl_convert_to_dB> {};
template<>
struct fex_gen_config<snd_ctl_convert_from_dB> {};
template<>
struct fex_gen_config<snd_hctl_compare_fast> {};
template<>
struct fex_gen_config<snd_hctl_open> {};
template<>
struct fex_gen_config<snd_hctl_open_ctl> {};
template<>
struct fex_gen_config<snd_hctl_close> {};
template<>
struct fex_gen_config<snd_hctl_nonblock> {};
template<>
struct fex_gen_config<snd_hctl_poll_descriptors_count> {};
template<>
struct fex_gen_config<snd_hctl_poll_descriptors> {};
template<>
struct fex_gen_config<snd_hctl_poll_descriptors_revents> {};
template<>
struct fex_gen_config<snd_hctl_get_count> {};
// template<> struct fex_gen_config<snd_hctl_set_compare> {};
template<>
struct fex_gen_config<snd_hctl_first_elem> {};
template<>
struct fex_gen_config<snd_hctl_last_elem> {};
template<>
struct fex_gen_config<snd_hctl_find_elem> {};
// template<> struct fex_gen_config<snd_hctl_set_callback> {};
// template<> struct fex_gen_config<snd_hctl_set_callback_private> {};
// template<> struct fex_gen_config<snd_hctl_get_callback_private> {};
template<>
struct fex_gen_config<snd_hctl_load> {};
template<>
struct fex_gen_config<snd_hctl_free> {};
template<>
struct fex_gen_config<snd_hctl_handle_events> {};
template<>
struct fex_gen_config<snd_hctl_name> {};
template<>
struct fex_gen_config<snd_hctl_wait> {};
template<>
struct fex_gen_config<snd_hctl_ctl> {};
template<>
struct fex_gen_config<snd_hctl_elem_next> {};
template<>
struct fex_gen_config<snd_hctl_elem_prev> {};
template<>
struct fex_gen_config<snd_hctl_elem_info> {};
template<>
struct fex_gen_config<snd_hctl_elem_read> {};
template<>
struct fex_gen_config<snd_hctl_elem_write> {};
template<>
struct fex_gen_config<snd_hctl_elem_tlv_read> {};
template<>
struct fex_gen_config<snd_hctl_elem_tlv_write> {};
template<>
struct fex_gen_config<snd_hctl_elem_tlv_command> {};
template<>
struct fex_gen_config<snd_hctl_elem_get_hctl> {};
template<>
struct fex_gen_config<snd_hctl_elem_get_id> {};
template<>
struct fex_gen_config<snd_hctl_elem_get_numid> {};
template<>
struct fex_gen_config<snd_hctl_elem_get_interface> {};
template<>
struct fex_gen_config<snd_hctl_elem_get_device> {};
template<>
struct fex_gen_config<snd_hctl_elem_get_subdevice> {};
template<>
struct fex_gen_config<snd_hctl_elem_get_name> {};
template<>
struct fex_gen_config<snd_hctl_elem_get_index> {};
// template<> struct fex_gen_config<snd_hctl_elem_set_callback> {};
// template<> struct fex_gen_config<snd_hctl_elem_get_callback_private> {};
// template<> struct fex_gen_config<snd_hctl_elem_set_callback_private> {};
template<>
struct fex_gen_config<snd_sctl_build> {};
template<>
struct fex_gen_config<snd_sctl_free> {};
template<>
struct fex_gen_config<snd_sctl_install> {};
template<>
struct fex_gen_config<snd_sctl_remove> {};
template<>
struct fex_gen_config<snd_mixer_open> {};
template<>
struct fex_gen_config<snd_mixer_close> {};
template<>
struct fex_gen_config<snd_mixer_first_elem> {};
template<>
struct fex_gen_config<snd_mixer_last_elem> {};
template<>
struct fex_gen_config<snd_mixer_handle_events> {};
template<>
struct fex_gen_config<snd_mixer_attach> {};
template<>
struct fex_gen_config<snd_mixer_attach_hctl> {};
template<>
struct fex_gen_config<snd_mixer_detach> {};
template<>
struct fex_gen_config<snd_mixer_detach_hctl> {};
template<>
struct fex_gen_config<snd_mixer_get_hctl> {};
template<>
struct fex_gen_config<snd_mixer_poll_descriptors_count> {};
template<>
struct fex_gen_config<snd_mixer_poll_descriptors> {};
template<>
struct fex_gen_config<snd_mixer_poll_descriptors_revents> {};
template<>
struct fex_gen_config<snd_mixer_load> {};
template<>
struct fex_gen_config<snd_mixer_free> {};
template<>
struct fex_gen_config<snd_mixer_wait> {};
// template<> struct fex_gen_config<snd_mixer_set_compare> {};
// template<> struct fex_gen_config<snd_mixer_set_callback> {};
// template<> struct fex_gen_config<snd_mixer_get_callback_private> {};
// template<> struct fex_gen_config<snd_mixer_set_callback_private> {};
template<>
struct fex_gen_config<snd_mixer_get_count> {};
template<>
struct fex_gen_config<snd_mixer_class_unregister> {};
template<>
struct fex_gen_config<snd_mixer_elem_next> {};
template<>
struct fex_gen_config<snd_mixer_elem_prev> {};
// template<> struct fex_gen_config<snd_mixer_elem_set_callback> {};
template<>
struct fex_gen_config<snd_mixer_elem_get_callback_private> {};
// template<> struct fex_gen_config<snd_mixer_elem_set_callback_private> {};
template<>
struct fex_gen_config<snd_mixer_elem_get_type> {};
template<>
struct fex_gen_config<snd_mixer_class_register> {};
// template<> struct fex_gen_config<snd_mixer_elem_new> {};
template<>
struct fex_gen_config<snd_mixer_elem_add> {};
template<>
struct fex_gen_config<snd_mixer_elem_remove> {};
template<>
struct fex_gen_config<snd_mixer_elem_free> {};
template<>
struct fex_gen_config<snd_mixer_elem_info> {};
template<>
struct fex_gen_config<snd_mixer_elem_value> {};
template<>
struct fex_gen_config<snd_mixer_elem_attach> {};
template<>
struct fex_gen_config<snd_mixer_elem_detach> {};
template<>
struct fex_gen_config<snd_mixer_elem_empty> {};
template<>
struct fex_gen_config<snd_mixer_elem_get_private> {};
template<>
struct fex_gen_config<snd_mixer_class_sizeof> {};
template<>
struct fex_gen_config<snd_mixer_class_malloc> {};
template<>
struct fex_gen_config<snd_mixer_class_free> {};
template<>
struct fex_gen_config<snd_mixer_class_copy> {};
// template<> struct fex_gen_config<snd_mixer_class_get_mixer> {};
// template<> struct fex_gen_config<snd_mixer_class_get_event> {};
// template<> struct fex_gen_config<snd_mixer_class_get_private> {};
// template<> struct fex_gen_config<snd_mixer_class_get_compare> {};
// template<> struct fex_gen_config<snd_mixer_class_set_event> {};
// template<> struct fex_gen_config<snd_mixer_class_set_private> {};
// template<> struct fex_gen_config<snd_mixer_class_set_private_free> {};
// template<> struct fex_gen_config<snd_mixer_class_set_compare> {};
template<>
struct fex_gen_config<snd_mixer_selem_channel_name> {};
template<>
struct fex_gen_config<snd_mixer_selem_register> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_id> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_name> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_index> {};
template<>
struct fex_gen_config<snd_mixer_find_selem> {};
template<>
struct fex_gen_config<snd_mixer_selem_is_active> {};
template<>
struct fex_gen_config<snd_mixer_selem_is_playback_mono> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_playback_channel> {};
template<>
struct fex_gen_config<snd_mixer_selem_is_capture_mono> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_capture_channel> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_capture_group> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_common_volume> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_playback_volume> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_playback_volume_joined> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_capture_volume> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_capture_volume_joined> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_common_switch> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_playback_switch> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_playback_switch_joined> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_capture_switch> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_capture_switch_joined> {};
template<>
struct fex_gen_config<snd_mixer_selem_has_capture_switch_exclusive> {};
template<>
struct fex_gen_config<snd_mixer_selem_ask_playback_vol_dB> {};
template<>
struct fex_gen_config<snd_mixer_selem_ask_capture_vol_dB> {};
template<>
struct fex_gen_config<snd_mixer_selem_ask_playback_dB_vol> {};
template<>
struct fex_gen_config<snd_mixer_selem_ask_capture_dB_vol> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_playback_volume> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_capture_volume> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_playback_dB> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_capture_dB> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_playback_switch> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_capture_switch> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_playback_volume> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_capture_volume> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_playback_dB> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_capture_dB> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_playback_volume_all> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_capture_volume_all> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_playback_dB_all> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_capture_dB_all> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_playback_switch> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_capture_switch> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_playback_switch_all> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_capture_switch_all> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_playback_volume_range> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_playback_dB_range> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_playback_volume_range> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_capture_volume_range> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_capture_dB_range> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_capture_volume_range> {};
template<>
struct fex_gen_config<snd_mixer_selem_is_enumerated> {};
template<>
struct fex_gen_config<snd_mixer_selem_is_enum_playback> {};
template<>
struct fex_gen_config<snd_mixer_selem_is_enum_capture> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_enum_items> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_enum_item_name> {};
template<>
struct fex_gen_config<snd_mixer_selem_get_enum_item> {};
template<>
struct fex_gen_config<snd_mixer_selem_set_enum_item> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_sizeof> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_malloc> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_free> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_copy> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_get_name> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_get_index> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_set_name> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_set_index> {};
template<>
struct fex_gen_config<snd_mixer_selem_id_parse> {};
template<>
struct fex_gen_config<snd_seq_open> {};
template<>
struct fex_gen_config<snd_seq_open_lconf> {};
template<>
struct fex_gen_config<snd_seq_name> {};
template<>
struct fex_gen_config<snd_seq_type> {};
template<>
struct fex_gen_config<snd_seq_close> {};
template<>
struct fex_gen_config<snd_seq_poll_descriptors_count> {};
template<>
struct fex_gen_config<snd_seq_poll_descriptors> {};
template<>
struct fex_gen_config<snd_seq_poll_descriptors_revents> {};
template<>
struct fex_gen_config<snd_seq_nonblock> {};
template<>
struct fex_gen_config<snd_seq_client_id> {};
template<>
struct fex_gen_config<snd_seq_get_output_buffer_size> {};
template<>
struct fex_gen_config<snd_seq_get_input_buffer_size> {};
template<>
struct fex_gen_config<snd_seq_set_output_buffer_size> {};
template<>
struct fex_gen_config<snd_seq_set_input_buffer_size> {};
template<>
struct fex_gen_config<snd_seq_system_info_sizeof> {};
template<>
struct fex_gen_config<snd_seq_system_info_malloc> {};
template<>
struct fex_gen_config<snd_seq_system_info_free> {};
template<>
struct fex_gen_config<snd_seq_system_info_copy> {};
template<>
struct fex_gen_config<snd_seq_system_info_get_queues> {};
template<>
struct fex_gen_config<snd_seq_system_info_get_clients> {};
template<>
struct fex_gen_config<snd_seq_system_info_get_ports> {};
template<>
struct fex_gen_config<snd_seq_system_info_get_channels> {};
template<>
struct fex_gen_config<snd_seq_system_info_get_cur_clients> {};
template<>
struct fex_gen_config<snd_seq_system_info_get_cur_queues> {};
template<>
struct fex_gen_config<snd_seq_system_info> {};
template<>
struct fex_gen_config<snd_seq_client_info_sizeof> {};
template<>
struct fex_gen_config<snd_seq_client_info_malloc> {};
template<>
struct fex_gen_config<snd_seq_client_info_free> {};
template<>
struct fex_gen_config<snd_seq_client_info_copy> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_client> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_type> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_name> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_broadcast_filter> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_error_bounce> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_card> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_pid> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_event_filter> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_num_ports> {};
template<>
struct fex_gen_config<snd_seq_client_info_get_event_lost> {};
template<>
struct fex_gen_config<snd_seq_client_info_set_client> {};
template<>
struct fex_gen_config<snd_seq_client_info_set_name> {};
template<>
struct fex_gen_config<snd_seq_client_info_set_broadcast_filter> {};
template<>
struct fex_gen_config<snd_seq_client_info_set_error_bounce> {};
template<>
struct fex_gen_config<snd_seq_client_info_set_event_filter> {};
template<>
struct fex_gen_config<snd_seq_client_info_event_filter_clear> {};
template<>
struct fex_gen_config<snd_seq_client_info_event_filter_add> {};
template<>
struct fex_gen_config<snd_seq_client_info_event_filter_del> {};
template<>
struct fex_gen_config<snd_seq_client_info_event_filter_check> {};
template<>
struct fex_gen_config<snd_seq_get_client_info> {};
template<>
struct fex_gen_config<snd_seq_get_any_client_info> {};
template<>
struct fex_gen_config<snd_seq_set_client_info> {};
template<>
struct fex_gen_config<snd_seq_query_next_client> {};
template<>
struct fex_gen_config<snd_seq_client_pool_sizeof> {};
template<>
struct fex_gen_config<snd_seq_client_pool_malloc> {};
template<>
struct fex_gen_config<snd_seq_client_pool_free> {};
template<>
struct fex_gen_config<snd_seq_client_pool_copy> {};
template<>
struct fex_gen_config<snd_seq_client_pool_get_client> {};
template<>
struct fex_gen_config<snd_seq_client_pool_get_output_pool> {};
template<>
struct fex_gen_config<snd_seq_client_pool_get_input_pool> {};
template<>
struct fex_gen_config<snd_seq_client_pool_get_output_room> {};
template<>
struct fex_gen_config<snd_seq_client_pool_get_output_free> {};
template<>
struct fex_gen_config<snd_seq_client_pool_get_input_free> {};
template<>
struct fex_gen_config<snd_seq_client_pool_set_output_pool> {};
template<>
struct fex_gen_config<snd_seq_client_pool_set_input_pool> {};
template<>
struct fex_gen_config<snd_seq_client_pool_set_output_room> {};
template<>
struct fex_gen_config<snd_seq_get_client_pool> {};
template<>
struct fex_gen_config<snd_seq_set_client_pool> {};
template<>
struct fex_gen_config<snd_seq_port_info_sizeof> {};
template<>
struct fex_gen_config<snd_seq_port_info_malloc> {};
template<>
struct fex_gen_config<snd_seq_port_info_free> {};
template<>
struct fex_gen_config<snd_seq_port_info_copy> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_client> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_port> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_addr> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_name> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_capability> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_type> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_midi_channels> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_midi_voices> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_synth_voices> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_read_use> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_write_use> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_port_specified> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_timestamping> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_timestamp_real> {};
template<>
struct fex_gen_config<snd_seq_port_info_get_timestamp_queue> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_client> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_port> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_addr> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_name> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_capability> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_type> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_midi_channels> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_midi_voices> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_synth_voices> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_port_specified> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_timestamping> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_timestamp_real> {};
template<>
struct fex_gen_config<snd_seq_port_info_set_timestamp_queue> {};
template<>
struct fex_gen_config<snd_seq_create_port> {};
template<>
struct fex_gen_config<snd_seq_delete_port> {};
template<>
struct fex_gen_config<snd_seq_get_port_info> {};
template<>
struct fex_gen_config<snd_seq_get_any_port_info> {};
template<>
struct fex_gen_config<snd_seq_set_port_info> {};
template<>
struct fex_gen_config<snd_seq_query_next_port> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_sizeof> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_malloc> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_free> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_copy> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_get_sender> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_get_dest> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_get_queue> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_get_exclusive> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_get_time_update> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_get_time_real> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_set_sender> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_set_dest> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_set_queue> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_set_exclusive> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_set_time_update> {};
template<>
struct fex_gen_config<snd_seq_port_subscribe_set_time_real> {};
template<>
struct fex_gen_config<snd_seq_get_port_subscription> {};
template<>
struct fex_gen_config<snd_seq_subscribe_port> {};
template<>
struct fex_gen_config<snd_seq_unsubscribe_port> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_sizeof> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_malloc> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_free> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_copy> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_client> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_port> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_root> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_type> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_index> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_num_subs> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_addr> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_queue> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_exclusive> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_time_update> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_get_time_real> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_set_client> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_set_port> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_set_root> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_set_type> {};
template<>
struct fex_gen_config<snd_seq_query_subscribe_set_index> {};
template<>
struct fex_gen_config<snd_seq_query_port_subscribers> {};
template<>
struct fex_gen_config<snd_seq_queue_info_sizeof> {};
template<>
struct fex_gen_config<snd_seq_queue_info_malloc> {};
template<>
struct fex_gen_config<snd_seq_queue_info_free> {};
template<>
struct fex_gen_config<snd_seq_queue_info_copy> {};
template<>
struct fex_gen_config<snd_seq_queue_info_get_queue> {};
template<>
struct fex_gen_config<snd_seq_queue_info_get_name> {};
template<>
struct fex_gen_config<snd_seq_queue_info_get_owner> {};
template<>
struct fex_gen_config<snd_seq_queue_info_get_locked> {};
template<>
struct fex_gen_config<snd_seq_queue_info_get_flags> {};
template<>
struct fex_gen_config<snd_seq_queue_info_set_name> {};
template<>
struct fex_gen_config<snd_seq_queue_info_set_owner> {};
template<>
struct fex_gen_config<snd_seq_queue_info_set_locked> {};
template<>
struct fex_gen_config<snd_seq_queue_info_set_flags> {};
template<>
struct fex_gen_config<snd_seq_create_queue> {};
template<>
struct fex_gen_config<snd_seq_alloc_named_queue> {};
template<>
struct fex_gen_config<snd_seq_alloc_queue> {};
template<>
struct fex_gen_config<snd_seq_free_queue> {};
template<>
struct fex_gen_config<snd_seq_get_queue_info> {};
template<>
struct fex_gen_config<snd_seq_set_queue_info> {};
template<>
struct fex_gen_config<snd_seq_query_named_queue> {};
template<>
struct fex_gen_config<snd_seq_get_queue_usage> {};
template<>
struct fex_gen_config<snd_seq_set_queue_usage> {};
template<>
struct fex_gen_config<snd_seq_queue_status_sizeof> {};
template<>
struct fex_gen_config<snd_seq_queue_status_malloc> {};
template<>
struct fex_gen_config<snd_seq_queue_status_free> {};
template<>
struct fex_gen_config<snd_seq_queue_status_copy> {};
template<>
struct fex_gen_config<snd_seq_queue_status_get_queue> {};
template<>
struct fex_gen_config<snd_seq_queue_status_get_events> {};
template<>
struct fex_gen_config<snd_seq_queue_status_get_tick_time> {};
template<>
struct fex_gen_config<snd_seq_queue_status_get_real_time> {};
template<>
struct fex_gen_config<snd_seq_queue_status_get_status> {};
template<>
struct fex_gen_config<snd_seq_get_queue_status> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_sizeof> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_malloc> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_free> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_copy> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_get_queue> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_get_tempo> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_get_ppq> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_get_skew> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_get_skew_base> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_set_tempo> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_set_ppq> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_set_skew> {};
template<>
struct fex_gen_config<snd_seq_queue_tempo_set_skew_base> {};
template<>
struct fex_gen_config<snd_seq_get_queue_tempo> {};
template<>
struct fex_gen_config<snd_seq_set_queue_tempo> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_sizeof> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_malloc> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_free> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_copy> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_get_queue> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_get_type> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_get_id> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_get_resolution> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_set_type> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_set_id> {};
template<>
struct fex_gen_config<snd_seq_queue_timer_set_resolution> {};
template<>
struct fex_gen_config<snd_seq_get_queue_timer> {};
template<>
struct fex_gen_config<snd_seq_set_queue_timer> {};
template<>
struct fex_gen_config<snd_seq_free_event> {};
template<>
struct fex_gen_config<snd_seq_event_length> {};
template<>
struct fex_gen_config<snd_seq_event_output> {};
template<>
struct fex_gen_config<snd_seq_event_output_buffer> {};
template<>
struct fex_gen_config<snd_seq_event_output_direct> {};
template<>
struct fex_gen_config<snd_seq_event_input> {};
template<>
struct fex_gen_config<snd_seq_event_input_pending> {};
template<>
struct fex_gen_config<snd_seq_drain_output> {};
template<>
struct fex_gen_config<snd_seq_event_output_pending> {};
template<>
struct fex_gen_config<snd_seq_extract_output> {};
template<>
struct fex_gen_config<snd_seq_drop_output> {};
template<>
struct fex_gen_config<snd_seq_drop_output_buffer> {};
template<>
struct fex_gen_config<snd_seq_drop_input> {};
template<>
struct fex_gen_config<snd_seq_drop_input_buffer> {};
template<>
struct fex_gen_config<snd_seq_remove_events_sizeof> {};
template<>
struct fex_gen_config<snd_seq_remove_events_malloc> {};
template<>
struct fex_gen_config<snd_seq_remove_events_free> {};
template<>
struct fex_gen_config<snd_seq_remove_events_copy> {};
template<>
struct fex_gen_config<snd_seq_remove_events_get_condition> {};
template<>
struct fex_gen_config<snd_seq_remove_events_get_queue> {};
template<>
struct fex_gen_config<snd_seq_remove_events_get_time> {};
template<>
struct fex_gen_config<snd_seq_remove_events_get_dest> {};
template<>
struct fex_gen_config<snd_seq_remove_events_get_channel> {};
template<>
struct fex_gen_config<snd_seq_remove_events_get_event_type> {};
template<>
struct fex_gen_config<snd_seq_remove_events_get_tag> {};
template<>
struct fex_gen_config<snd_seq_remove_events_set_condition> {};
template<>
struct fex_gen_config<snd_seq_remove_events_set_queue> {};
template<>
struct fex_gen_config<snd_seq_remove_events_set_time> {};
template<>
struct fex_gen_config<snd_seq_remove_events_set_dest> {};
template<>
struct fex_gen_config<snd_seq_remove_events_set_channel> {};
template<>
struct fex_gen_config<snd_seq_remove_events_set_event_type> {};
template<>
struct fex_gen_config<snd_seq_remove_events_set_tag> {};
template<>
struct fex_gen_config<snd_seq_remove_events> {};
template<>
struct fex_gen_config<snd_seq_set_bit> {};
template<>
struct fex_gen_config<snd_seq_unset_bit> {};
template<>
struct fex_gen_config<snd_seq_change_bit> {};
template<>
struct fex_gen_config<snd_seq_get_bit> {};
template<>
struct fex_gen_config<snd_seq_control_queue> {};
template<>
struct fex_gen_config<snd_seq_create_simple_port> {};
template<>
struct fex_gen_config<snd_seq_delete_simple_port> {};
template<>
struct fex_gen_config<snd_seq_connect_from> {};
template<>
struct fex_gen_config<snd_seq_connect_to> {};
template<>
struct fex_gen_config<snd_seq_disconnect_from> {};
template<>
struct fex_gen_config<snd_seq_disconnect_to> {};
template<>
struct fex_gen_config<snd_seq_set_client_name> {};
template<>
struct fex_gen_config<snd_seq_set_client_event_filter> {};
template<>
struct fex_gen_config<snd_seq_set_client_pool_output> {};
template<>
struct fex_gen_config<snd_seq_set_client_pool_output_room> {};
template<>
struct fex_gen_config<snd_seq_set_client_pool_input> {};
template<>
struct fex_gen_config<snd_seq_sync_output_queue> {};
template<>
struct fex_gen_config<snd_seq_parse_address> {};
template<>
struct fex_gen_config<snd_seq_reset_pool_output> {};
template<>
struct fex_gen_config<snd_seq_reset_pool_input> {};
template<>
struct fex_gen_config<snd_midi_event_new> {};
template<>
struct fex_gen_config<snd_midi_event_resize_buffer> {};
template<>
struct fex_gen_config<snd_midi_event_free> {};
template<>
struct fex_gen_config<snd_midi_event_init> {};
template<>
struct fex_gen_config<snd_midi_event_reset_encode> {};
template<>
struct fex_gen_config<snd_midi_event_reset_decode> {};
template<>
struct fex_gen_config<snd_midi_event_no_status> {};
template<>
struct fex_gen_config<snd_midi_event_encode> {};
template<>
struct fex_gen_config<snd_midi_event_encode_byte> {};
template<>
struct fex_gen_config<snd_midi_event_decode> {};
