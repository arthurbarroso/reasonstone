open Css;

let navbarContainer = 
  merge([
    style([
      display(flexBox),
      width(auto),
      padding4(~top=`percent(4.), ~right=`percent(20.), ~bottom=`percent(6.), ~left=`percent(20.)),
      display(flexBox),
      flexDirection(row),
      alignItems(center),
      justifyContent(spaceBetween)
    ]),
      "navbar-container"
    ]);

let asideContainer =
  merge([
    style([
      justifyContent(spaceBetween)
    ]),
    "aside-container"
  ]);

[@react.component]


let make = () => {
  <div className=navbarContainer>
    <Link href="/" name="reasonstone" strong=true />
    <div className=asideContainer>
      <Link href="/" name="about" />
      <Link href="/" name="contact" />
    </div>
  </div>
};

