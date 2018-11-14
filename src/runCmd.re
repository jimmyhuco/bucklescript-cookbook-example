let () =
  /* prints node's version */
  Node.(
    Child_process.execSync(
      "node -v",
      Child_process.option(~encoding="utf8", ()),
    )
  )
  |> Js.log;