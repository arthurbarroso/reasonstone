open Css;

let sectionStyle =
  merge([
    style([
      display(flexBox),
      flexDirection(column),
      alignItems(center),
      width(`percent(100.))
    ]),
    "section-style"
  ]);

[@react.component]
let make = (~title: option(string)=?, ~content: string) => {

  let sectionTitle =
    switch(title){
      | Some(title) => <h1>{ReasonReact.string(title)}</h1>;
      | None => React.null;
    };

  <section className=sectionStyle>
    sectionTitle
    <p>{content |> ReasonReact.string}</p>
  </section>
}