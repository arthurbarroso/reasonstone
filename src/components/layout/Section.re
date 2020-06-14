open Css;

let sectionStyle =
  merge([
    style([
      display(flexBox),
      flexDirection(column),
      width(auto),
      padding4(~top=`percent(0.), ~right=`percent(8.), ~bottom=`percent(6.), ~left=`percent(8.)),      
    ]),
    "section-style"
  ]);

[@react.component]
let make = (~child: option(React.element)=?, ~title: option(string)=?, ~content: option(string)=?, ) => {

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

  let children =
    switch(child) {
      | Some(child) => child;
      | None => React.null
    };

  <section className=sectionStyle>
    sectionTitle
    sectionContent
    children
  </section>
}