[@react.component]

let make = (~image: option(string)=?) => {

  let cardImg =
    switch(image){
      | None => React.null;
      | Some(image) => <img key=image src=image alt="card-image" />
    };
/* 
    let cardName =
    switch(name){
      | None => React.null;
      | Some(name) => <h1>{ReasonReact.string(name)}</h1>
    };
  
  let cardText =
    switch(text){
      | None => React.null;
      | Some(text) => <p>{ReasonReact.string(text)}</p>
    }; */
  
  /* let cardMana =
    switch(manaCost){
      | None => React.null;
      | Some(manaCost) => <p>{ReasonReact.string(string_of_int(manaCost))}</p>
    }; */

    cardImg;
}