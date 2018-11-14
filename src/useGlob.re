let () =
  /* find and list all javascript files in subfolders */
  Glob.glob("**/*.js", (_, files) => Array.iter(Js.log, files));