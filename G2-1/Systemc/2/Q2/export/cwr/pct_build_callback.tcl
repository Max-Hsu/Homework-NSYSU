::namespace eval ::pct::build {
    proc add_vpsim_path { fromPath toPath } {
        while { [string first "\\" "$fromPath"] >= 0 } {
            set idx [string first "\\" "$fromPath"]
            set fromPath [string replace "$fromPath" $idx $idx "/" ]
        }
        if {[file isdirectory "$fromPath"]} {
            foreach childPath [glob -nocomplain -directory "$fromPath" "*"] {
                set newToPath "$toPath/[file tail $fromPath]"
                ::file mkdir "$newToPath"
                add_vpsim_path "$childPath" "$newToPath"
            }
        } else {
            if {![file isdirectory "$toPath"] && \
                [file dirname "$toPath"] != "."} then {
              ::file mkdir [file dirname "$toPath"]
            }
            ::file copy -force -- "$fromPath" "$toPath"
        }
    }
    proc add_vppack_path { fromPath toPath } {
        while { [string first "\\" "$fromPath"] >= 0 } {
            set idx [string first "\\" "$fromPath"]
            set fromPath [string replace "$fromPath" $idx $idx "/" ]
        }
        if {[file isdirectory "$fromPath"]} {
            foreach childPath [glob -nocomplain -directory "$fromPath" "*"] {
                add_vppack_path "$childPath" "$toPath/[file tail $fromPath]"
            }
        } else {
            ::scsh::vp::add_file_to_package "$fromPath" "$toPath"
        }
    }
  proc callback {args} {
    [namespace current]::add_vppack_path "[::subst -nobackslashes -nocommands {/home/B073040049/Desktop/B073040049_HW2/Q2/export/parameters/HARDWARE.unevald.parameters}]" "[::subst -nobackslashes -nocommands {simulation/parameters}]"
  }
  ::scsh::add_build_callback [::namespace current]::callback
}
