let () = Random.init(int_of_float(Js.Date.now()));
let () = Random.int(5) |> Js.log;