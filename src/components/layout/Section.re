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
let make = (~title: option(string)=?, ~content: option(string)=?) => {

  let sectionTitle =
    switch(title){
      | Some(title) => <h1>{ReasonReact.string(title)}</h1>;
      | None => React.null;
    };

  let sectionContent =
    switch(content){
      | Some(content) => <p>{ReasonReact.string(content)}</p>;
      | None => React.null;
    };

  <section className=sectionStyle>
    sectionTitle
    sectionContent
  </section>
}