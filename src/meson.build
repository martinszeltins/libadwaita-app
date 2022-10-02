showhide_sources = [
  'main.c',
  'app.c',
  'window.c',
]

showhide_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
]

showhide_sources += gnome.compile_resources('showhide-resources',
  'gresource.xml',
  c_name: 'showhide'
)

executable('showhide', showhide_sources,
  dependencies: showhide_deps,
       install: true,
)
