import React from 'react';

const ReleaseForm = ({submitHandler}) => {

    let _releaseName, _releaseDate;
    const handleSubmit = (e) => {
        console.log('ReleaseForm -> handleSubmit');
        console.log(_releaseName.value);
        console.log(_releaseDate.value);
    }
    return(
        <form onSubmit={handleSubmit} className="form-inline">
            <div className="form-row align-items-center">
                <div className="col-auto">
                <label className="sr-only" for="inlineFormInput">Release Name</label>
                <input type="text" ref={input => _releaseName = input} className="form-control mb-2" id="inlineFormInput" placeholder="Release Name"/>
                </div>
                <div className="col-auto">
                <label className="sr-only" for="inlineFormInputGroup">Release Date</label>
                <div className="input-group mb-2">
                    <div className="input-group-prepend">
                    </div>
                    <input type="text" ref={input => _releaseDate = input} className="form-control" id="inlineFormInputGroup" placeholder="Release Date"/>
                </div>
                </div>
                <div className="col-auto">
                </div>
                <div className="col-auto">
                <button type="submit" className="btn btn-primary mb-2">Submit</button>
                </div>
            </div>
        </form>
    );
}

export default ReleaseForm;
