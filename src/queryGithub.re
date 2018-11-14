/* given an array of repositories object as a JSON string */
/* returns an array of names */
let names = text =>
  text |> Js.Json.parseExn |> Json.Decode.(array(field("name", string)));

/* fetch all public repositories of user [reasonml-community] */
/* print their names to the console */
let printGithubRepos = () =>
  Js.Promise.(
    Fetch.fetch("https://api.github.com/users/reasonml-community/repos")
    |> then_(Fetch.Response.text)
    |> then_(text => text |> names |> Array.iter(Js.log) |> resolve)
    |> ignore
  );

let () = printGithubRepos();
